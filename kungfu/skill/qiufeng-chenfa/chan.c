// chan.c ��糾�� ���־�

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
        object weapon;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("ǣ�ƹ���ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( (int)me->query("neili") < 200 )
		return notify_fail("��������������ߣ�\n");

	if( (int)me->query_skill("qiufeng-chenfa", 1) < 60)
		return notify_fail("����糾������Ϊ����������ʹ�ò��־�! \n");

        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "whip")
                        return notify_fail("��ʹ�õ��������ԡ�\n");

	if( target->is_busy() )
		return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɡ�\n");

	msg = CYN "$Nʹ����糾���������־�������������ͼ��$n��ȫ���ס��\n";

	me->start_busy(1);
	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
		msg += "���$p��$P���˸����ֲ�����\n" NOR;
		target->start_busy( (int)me->query_skill("qiufeng-chenfa") / 60 + 2);
	} else {
		msg += "����$p������$P����ͼ����û���ϵ���\n" NOR;
		me->start_busy(4);
	}
	message_combatd(msg, me, target);
	me->add("neili",-100);
	if(!target->is_fighting(me)) target->fight_ob(me);
	return 1;
}
