
#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("��Ψ�Ҷ���ֻ�ܶ�ս���еĶ���ʹ�á�\n");


	msg = RED "$N˫Ŀ���࣬���������׹�צ���һʽ��Ψ�Ҷ��𡹣�";

	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
		msg += "���$p��$P���˸����ֲ�����\n" NOR;
		target->receive_damage("qi",(int) me->query("max_qi")/2);
		target->receive_wound("jing", ((int) me->query("max_jing"))/2);
	} else {
		msg += "����$p���Ƕ����$P�����һ������\n" NOR;
	}
	message_vision(msg, me, target);
        me->unconcious();
	return 1;
}
