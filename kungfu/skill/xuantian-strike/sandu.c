// sandu.c ���������ɢ��
// By Yzuo 97.04

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("ʩ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( !target || !target->is_character() )
		return notify_fail("ʩ��ֻ�ܶԶ���ʹ�á�\n");
	if( !(int)me->query_condition("poison_sandu"))
		return notify_fail("������û����ɢ��\n");

	if( environment(me)->query("no_fight") )
		return notify_fail("���ﲻ�ܹ�������! \n");

//	if( !userp(target) || wizardp(target) )
//		return notify_fail("ɢ��ֻ�ܶ����ʹ�á�\n");

	if( (int)target->query("combat_exp") < (int)me->query("combat_exp") )
		return notify_fail("������ɢ����û�õġ�\n");

	if( (int)me->query_skill("huagong-dafa", 1) < 40 )
		return notify_fail("��Ļ����󷨲�����죬����ɢ����\n");

	if( (int)me->query_skill("xuantian-strike", 1) < 40 )
		return notify_fail("�����������Ʋ�����죬����ɢ����\n");

	msg = GRN "ֻ����$N�Ĺǽڸ�����죬$N�����͵س��˰�ߣ���Ȼһ��ץס$n��
�󣬽������������ģ�ԴԴ���ϴ���$n���ڡ�\n";

	me->start_busy(1);
	if( random( (int)me->query_skill("xuantian-strike",1))
          > random(target->query_skill("dodge") ) ) {
		msg += CYN " ���$p����������$P�ı�����������ɢ��$n���ڣ�\n" NOR;
            target->receive_damage("qi",20);
            target->receive_wound("qi",15 + random(10));
	 target->apply_condition("xx_sandu",20);
	 target->apply_condition("x2_sandu",20);
	 target->apply_condition("sanpoison",20);
            target->apply_condition("poison_sandu", 1000);
            me->apply_condition("poison_sandu", 0);
            target->start_busy(1 + random(2));
		message_combatd(msg, me, target);
		COMBAT_D->report_status(target);

	} else {
		msg += "����$p������������һ�𣬽�$N�������˿�ȥ��\n" NOR;
		me->start_busy(3);
		message_combatd(msg, me, target);
	}
me->kill_ob(target);
//	if( !target->is_killing(me) ) target->kill_ob(me);
	return 1;
}
