// jingmo.c һָ�� ����ħһָ��

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("��ħһָֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if((int)me->query_str() < 30)
		return notify_fail("���������,����ʹ����һ����!\n");

	if((int)me->query_skill("hunyuan-yiqi",1) < 100)
		return notify_fail("���Ԫһ�����Ĺ�����������ʹ�þ�ħһָ!\n");

	if((int)me->query_skill("yizhi-chan",1) < 150)
		return notify_fail("���ָ����Ϊ����,Ŀǰ������ʹ�þ�ħһָ����!\n");

	if((int)me->query("neili") < 800)
		return notify_fail("���������ڲ���, ����ʹ�þ�ħһָ! \n");

	if( target->is_busy() )
		return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɢ�\n");

	msg = HIY "$Nʹ��һָ����������ħһָ������ס��$n��ȫ��ҪѨ, ʹ$n�������á�\n"NOR;

	if( random(me->query("combat_exp")) > (int)target->query("combat_exp") / 2 ) {
		msg += "���$p��$P���˸����ֲ�����\n" NOR;
		target->start_busy( (int)me->query_skill("yizhi-chan",1) / 60 + 2);
		me->add("neili", -150);
	} else {
		msg += "����$p������$P����ͼ����û���ϵ���\n" NOR;
		me->start_busy(2);
	}
	message_combatd(msg, me, target);

	return 1;
}
