 //mimicat@fy4
#include <ansi.h>
inherit F_SSERVER;
int perform(object me, object target)
{       
        int extra,my_exp,bonus,damage;
        
        extra=me->query_skill("kwan-yin-spells",1);
        my_exp=me->query("combat_exp");
        
        
        if(extra<60) return notify_fail("��Ĺ����������䲻��������\n");
        
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("��������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
                
        if( me==target)
                return notify_fail("���Է������������Լ����ϡ�\n"); 
        if( (int)me->query("neili") < 200 )
                return notify_fail("��ķ���������\n"); 
        message_vision(
                HIR "$N���ڡ�������Ϊһ�壬��ɫׯ�أ���������������� \n"NOR,
                        me, target );
        
        extra=extra*extra*100;
        
        if(my_exp/2+random(my_exp)*3/2+random(extra)>target->query("combat_exp"))
        {
                message_vision(RED"$nֻ������ͷ�����ش�һ��������ƺ�Ҫ���϶�ȥ�� \n\n"NOR,me,target);
                damage=30 + (int)me->query_skill("magic") + random((int)me->query_skill("magic"));
                if (damage>target->query("jing")) damage=target->query("jing")/2;
                target->receive_wound("jing", damage);
                COMBAT_D->report_status(target);
                //COMBAT_D->win_lose_check(me,target,1);
        }
        else
                message_vision(RED"$nֻ������ͷһ������æ�������ġ� \n"NOR,me,target); 
		me->add("neili", -100);
        
        me->start_busy(2);
        return 1;
}   
