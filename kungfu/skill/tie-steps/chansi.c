// chansi.c
//written by kouga
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
void remove_effect(object me, int amount);
int perform(object me, object target)
{
        int skill;
	string msg;
	object weapon;
	skill = me->query_skill("tie-steps",1);
	if(skill < 100) return notify_fail("�����Ѫʮ����̫���ˣ�\n"); 
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�۲�˿�ƣ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	if(me->is_busy())
		return notify_fail("������û�գ���\n");
        if( (int)me->query("neili") < 100 )     return
        notify_fail("�������������\n");
        if( (int)target->query_temp("chansi") ) return 
	notify_fail("���Ѿ���ʩչ�۲�˿�ƣ��ˡ�\n");
       	if((int)target->query("combat_exp") < random((int)me->query("combat_exp")*skill/40))
	{
		me->add("neili", -100);
        	message_vision( HIR
		"$N����һԾ��ʹ���۲�˿�ƣݣ�$n�����������Ӱ�죬�����ɬ������\n" NOR, me,target);
        	target->add_temp("apply/dodge", -skill/3);
		target->add_temp("apply/parry",-skill/3);       
        	target->set_temp("chansi", 1);
        	target->start_call_out( (: call_other, __FILE__, "remove_effect", target, 
-skill/3 :), skill/5);
        	me->start_busy(1);
	}
	else
	{
		msg = "��ϧ$N������$n����������ѸȻ������";
		COMBAT_D->do_attack(target,me, target->query_temp("weapon"),TYPE_REGULAR,msg);	
        	me->start_busy(1);
	}
        return 1;
}

void remove_effect(object target, int amount)
{
        target->add_temp("apply/dodge", - amount);
	target->add_temp("apply/parry",- amount);
        target->delete_temp("chansi");
        message_vision("$N���ڰ����ˣ۲�˿�ƣݵ�Ӱ�졣\n",target);
}
 
