// riyue ���±�-����
// campsun

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        string msg,dodge_skill;
object weapon = me->query_temp("weapon");

        if( !target ) target = offensive_target(me);

        if( !target || !me->is_fighting(target) )
                return notify_fail("��������ת��ֻ����ս���жԶ���ʹ�á�\n");

        if (!weapon || weapon->query("skill_type") != "whip")
                return notify_fail("����û������,���ʹ�á�������ת����\n");

        if( (int)me->query_skill("riyue-bian", 1) < 200 )
                return notify_fail("������±޷�������죬����ʹ�á�������ת����\n");

        if( (int)me->query_skill("yijinjing", 1) < 200 )
                return notify_fail("����׽�ȼ�����������ʹ�á�������ת����\n");

if( (int)me->query_skill("buddhism", 1) < 200 )
                return notify_fail("��������ķ��ȼ�����������ʹ�á�������ת����\n");
          
               
        if( (int)me->query("neili") < 1000 )
                return notify_fail("����������̫��������ʹ�á����¡���\n");

        msg = HIR "$N���и�����ţ�ʹ�����±��С����¡����������г����������裬���������Ҳ������϶�������$n,\n" NOR;
	msg += HIR "����$N����һ��������������צ��ī�����ƣ��������ϣ�����$n�˵���\n";
        message_vision(msg, me, target);
me->set_temp("riyue", 1);
	me->add_temp("apply/attack", 60);	
	me->add_temp("apply/damage", 200);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1); 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
   	me->add_temp("apply/attack", -60);	
	me->add_temp("apply/damage", -200);
 if ((int)me->query_skill("riyue-bian", 1)>200) {          
        msg = HIY"������$N�����������ӷ𣡡���ʹ�����ա��־������г���һ���$n���ʺ��ȥ����ͷδ����������Ю
����������յ��գ���Է�һ�����ϣ�ֻ������žž���������죬��ͷ���𣬱���һ�������Ķ��ߺ��ط�
�ɻӶ�������������ɳ����Х������\n";     
        message_vision(msg, me, target);
	me->add_temp("apply/attack", 80);	
	me->add_temp("apply/damage", 300);
              COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
	me->add_temp("apply/attack", -80);	
	me->add_temp("apply/damage", -300);
        me->delete_temp("riyue");      
        

        me->add("neili", -400);

        me->start_busy(2);

        }
else { 
msg = BCYN "������$N�������ҷ�ȱ�������ʹ�����¡��־����������տ�����������������¶��ǣ����г����趯ʱ
�Ʋ������Ӱ��������Ϣ���ƻ�ʵ����ȴ���ް�������������ȣ�˵�����Ĺ���Ī����\n"NOR;
	message_vision(msg,me,target);
	if (random(10)>4) 
		{msg=HIR"���$nһ��С�ģ���ʱ��û��$N�����������Ӱ֮�С�\n"NOR;
message_vision(msg,me,target);        
me->delete_temp("riyue");      
              target->start_busy(3+random(5));
			me->add("neili",-400);}
	else {
         dodge_skill = target->query_skill_mapped("dodge");
	 if( !dodge_skill ) dodge_skill = "dodge";
         message_vision(SKILL_D(dodge_skill)->query_dodge_msg(target, 1), me, target);

		
me->delete_temp("riyue");      
		me->add("neili",-200);
		}
	}
return 1;

}
