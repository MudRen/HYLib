// sheshen.c ����
/*              msg += HIC "$n����$N�ô���������æ���ң��Ǳ���״�Ķ�����ȥ�������ŵ������������һ�󶯵����á�\n" NOR;
*/

#include <ansi.h>

inherit F_SSERVER;


int perform(object me, object target)
{
        mapping skill_status;
        string msg, *sname;
        object weapon;
        int exp, shen, mine, count,damage;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( me->is_ghost() || me->query("eff_qi") <0 )
                return notify_fail("���Ѿ����ˡ�\n");
      if( objectp(me->query_temp("weapon")) )
           return notify_fail("��������ʹ�ã�\n");    

        if( me->is_busy() )
                return notify_fail("������æ���أ�ʹ������һ�С�\n");




        if( (int)me->query_skill("diwangquan") < 250 )
                return notify_fail("��������书������죬����ʹ������\n");
        if( me->query("neili") >= 800 || me->query("qi") >= 300)
                                         return notify_fail("��δ��ɽ��ˮ��֮�أ������ô˺��У�\n");
        if( (int)me->query_skill("shenlong-xinfa", 1) < 250  )
                return notify_fail("����ڹ���Ϊ����������ʹ������\n");

        if( me->query_skill_mapped("force") != "shenlong-xinfa")
                                         return notify_fail("�����õ��ڹ���Ӣ��������·��㣣�\n");

                  if( me->query("combat_exp") < 1500000)
                                         return notify_fail("��ʵս���鲻�㣬����ʹ������\n");

        if (target->query("shen") > 10000)
                shen = - (int)me->query("shen")/50;
        else shen = (int)me->query("shen")/50;

        exp = (int)me->query("combat_exp")/100;

        msg = HIW"$Nһ����Х�����Ŵ󿪣�ȫ��ײ��$n"+HIW"���Ѿ���ƴ���Ĵ򷨣�����\n"NOR;

        mine = random(me->query("combat_exp") -me->query("shen"));
        
        if( mine > (int)target->query("combat_exp")/3*2 )
        {
                msg += HIR"$n"+HIR"⧲�����֮�£���$N�˸����ţ�ֻ�����������ޱȣ�ȴ�ֻ��������ã�\n�̲�ס�˷���һ���������ĲҽУ�����$n��Ŀ����������£�����ǰ����������ֹͣ�ˡ�\n���˶��ľ����е�������ֻ���¾��Ķ��ǵı���һĻ������\n" NOR;
                message_vision(msg, me, target);
                me->add("max_neili", -(30+random(30)) );
                me->add("combat_exp", -exp);
                me->add("shen", shen);
if (userp(target))
{
                me->receive_wound("qi", me->query("max_qi")+200);
                target->receive_wound("qi", target->query("max_qi")+200);
                me->start_busy(3 + random(3));
                target->start_busy(3 + random(3));
                //me->set_temp("die_reason","��"+target->name(1)+"ͬ���ھ�");
                //target->set_temp("die_reason","��"+me->name(1)+"ͬ���ھ�");
                me->die();
                target->die();
}
else
{
                damage=random(target->query("max_qi"))+800;
                if (damage > 25000) damage=25000;
                target->receive_wound("qi", damage);

                damage=random(me->query("max_qi"))+800;
                if (damage > 25000) damage=25000;
                me->receive_wound("qi", damage);
                
                me->start_busy(3 + random(3));
                target->start_busy(3 + random(3));
	
}
                return 1;

        } 
        else
        {
                msg += HIC "$n" HIC "����$N" HIC "�ô���������æ���ң��Ǳ���״�Ķ�����ȥ�������ŵ������������һ�󶯵����á�\n"NOR;
                message_vision(msg, me, target);
if (userp(target))
{
                me->receive_wound("qi", me->query("max_qi")+200);
                me->start_busy(3);
                me->die();
}
else
{
                damage=random(me->query("max_qi"))+800;
                if (damage > 25000) damage=25000;
                me->receive_wound("qi", damage);
                me->start_busy(3 + random(3));

}	
                target->start_busy(3 + random(3));
                return 1;

        }

        return 1;
}

