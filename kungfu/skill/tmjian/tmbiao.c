
// tmbiao.c  ��ħ�
// 99.2.5 by Bless

#include <ansi.h>
inherit F_SSERVER;

int perform(object me,object target)
{
        int damage,i,j;
        string msg;     
        object ob;
        if( !target ) target = offensive_target(me);

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
            return notify_fail("������û��װ������������\n");

        if(!target||!target->is_character() || !me->is_fighting(target) )
            return notify_fail("����ħ쮡�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

    if (me->query("family/family_name") != "�������" )
        return notify_fail("�㲻��������̵��ӣ�����ʹ�����������\n");
        
        if ( (int)me->query_dex() < 30 )
            return notify_fail("������첻�㣬����������ħ쮡����\n");

        if( (int)me->query_skill("tmjian",1)<181)
            return notify_fail("�����ħ����������죬����ʹ�á���ħ쮡���\n");

        if( (int)me->query_skill("tmdafa",1)<101)
            return notify_fail("�����ħ�󷨲�����񣬲���ʹ�á���ħ쮡���\n");
                                
        if( (int)me->query("neili")<500)
                return notify_fail("����������̫��������ʹ�á���ħ쮡���\n");
                        
        me->start_busy(3);
        target->start_busy(3);

        me->add("neili",-350);
                
        damage =(target->query_skill("dodge")+target->query_skill("parry"))/2;

        if (damage==0||!damage) damage=1;
        damage = me->query_skill("tmjian",1)*400/damage;
        damage+= me->query_skill("force")*500/
                ((int)target->query_skill("force")+1);
        damage+= me->query("combat_exp")*4000/ 
                (target->query("combat_exp")+1);

        if(damage>6000) damage = 6000;
        if(damage<500 ) damage = 550;
                
        i = random(damage);
        j = me->query_skill("tmjian",1)/2+2500;
        damage = (damage/10+i/10)*j/2000+500;

        msg=YEL"\n\n$N����ͻȻ������ת������һ���쮣�����"+ob->query("name")+"��������ħӰ������ޱȵ�����$n��ȥ��\n"NOR;

       if(random((int)target->query("combat_exp")/3*2) < (int)me->query("combat_exp"))
        {
if (damage >5000) damage=5000;
                target->receive_damage("qi",damage);
                target->receive_wound("qi",damage);

                msg += HIY"$n��ʧɫ���������ѣ����վ�û���ӳ���ħ�����ķ�Χ����\n"NOR;      
       if((random((int)target->query("combat_exp")/3*2) > (int)me->query("combat_exp")) &&
       (random((int)target->query("combat_exp")/3) < (int)me->query("combat_exp")))
                        msg += HIY"���$n�ļ��$N��ȥһ���Ƥ�⣬Ѫ���Ľ���\n"NOR;
                else if( damage < 500 ) 
                        msg += HIR"$n��$N����"+ob->query("name")+"���ص����ڶ��ţ�ҡҡ������\n"NOR;
                else 
                        msg += RED"$n��ǰһ����ɲ�Ǽ��ѱ�$N���С�̴�С���Ѩ��������������Ѫ��\n\n\n"NOR;
        }
        else
        {
                msg += YEL"����$p������$P����ͼ������һ�����˿�ȥ��\n\n\n"NOR;
     me->start_busy(2);
        }               

        message_vision(msg, me, target);

        return 1;
}
