// feixue.c �����ѩ 



#include <ansi.h>
#include <combat.h>
#include <weapon.h>



inherit F_SSERVER;



int perform(object me, object target)

{
        string msg;
        int damage, attp, defp;

        object obj;

        string w_name;


    object weapon;
        w_name = me->query("weapon/name");

        obj = me->query_temp("weapon");
        


        if( !target ) target = offensive_target(me);


    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
        return notify_fail("��ʲô��Ц��ûװ��������ʹ�������ѩ����\n");

        if( !target || !target->is_character() || !me->is_fighting(target) )

                return notify_fail("�������ѩ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");


   if(me->query_skill_mapped("force") != "xuantian-wuji" )
	return notify_fail("��û���������޼���\n");

        if ((int)me->query_skill("liangyi-jian", 1) < 60)

   return notify_fail("��������ǽ���������죬�޷�ʹ�����ǽ�����֮һ�ġ������ѩ����\n");



        if ((int)me->query_skill("xuantian-wuji", 1) < 70)

                return notify_fail("��������޼������̫ǳ���޷�ʹ���������ѩ����\n"); 

//         if ((int)me->query_skill("throwing", 1) < 60)

//                return notify_fail("��ġ��������������̫ǳ���޷�ʹ���������ѩ����\n"); 

        if ((int)me->query("neili",1) < 500)

                return notify_fail("��������������޷�ʹ�����ǽ��С������ѩ���ľ�����\n"); 
    if( (int)me->query_skill("art", 1) > 80 )
    {
    msg = HIC"$n��������ƫ�󣬼�������ת����ֻ��һɲ������ɲʱϮ�����ף�"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg = HIG"$n��������ƫ�ң���������ת����ֻ��һɲ������ɲʱϮ�����ף�"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg = HIY"$n��������ƫ�ϣ���������ת����ֻ��һɲ������ɲʱϮ������"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg = HIR"$n��������ƫ�£���������ת����ֻ��һɲ������ɲʱϮ������"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    }
        message_vision( HIW "$N���һ���������ڽ���Ĭ��������ֻ�������һ�������Ϊ֮һ�ϣ����������㣬$N����\n"

         + "��������Ϊ������Ƭ���������ѩ����$n���������\n"NOR, me, target );



        attp = me->query_skill("xuantian-wuji",1) + me->query_skill("liangyi-jian",1);

        defp = target->query_skill("dodge");




        if( random( attp ) > random( defp ) )

        {

                damage = me->query_skill("liangyi-jian",1) + (int)me->query_skill("xuantian-wuji", 1)*2;

                damage = damage - random( target->query_skill("dodge")/3 );



                if( objectp(obj)&&w_name!=obj->query("name") )

                {


                        target->receive_damage("qi", 220 + random(damage))*3;

                        target->receive_wound("qi", 220 + damage)*3;



                        target->start_busy(2 + random(8));

                }

                else

                {


                        target->receive_damage("qi", 220 + random(damage));

                        target->receive_wound("qi", 220 + damage);



                        me->start_busy(3);

                        target->start_busy(3 + random(4));

                }

        }

        else {

                message_vision( HIY "$p���Ų�æ�ػζ����Σ�˲ʱ�����˽��ꡣ\n" NOR, me, target );

                me->start_busy(4);

        }



//        if( !target->is_killing(me) ) target->kill_ob(me);



        me->add("neili", -300);



if (random(2)==0) me->start_busy(3);


        return 1;

}



