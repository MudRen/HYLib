// cuixin.c  �����ơ����ġ�

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	int damage;
	string msg;

	if( !target ) target = offensive_target(me);
	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("�����ġ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if( me->query_temp("weapon"))
                return notify_fail("������������ô��ʹ�á����ġ���\n");   

	if( (int)me->query_skill("cuixin-zhang", 1) < 150 )
		return notify_fail(WHT"��Ĵ����Ʋ�����죬��ʹ���������ġ���\n"NOR);
	if( (int)me->query_skill("force", 1) < 180 )
		return notify_fail(RED"����ڹ��ķ���򲻹���ʹ�á����ġ��������Լ��ľ�����\n"NOR);
	if( !target->is_busy() )
		return notify_fail(RED"�����ġ�ֻ�ܳ�æ���жԶ���ʹ�á�\n"NOR);
	if( (int)me->query("neili") < 800 )
		return notify_fail("�����������ˡ�\n");

	msg = HIC "$N����һЦ������$næ���еݳ�һ�ơ�\n"NOR;
	msg += HIB "$N���������ᣬ��һ�����������ȴֱ͸$n������\n"NOR;
	me->start_busy(3);
        me->start_perform(3, "����");
	me->add("neili", -600);
	damage = target->query("qi");
	if (userp(target))
{
	if (	random(me->query("combat_exp")) > target->query("combat_exp")/2	)
{
		target->receive_damage("qi", damage/6);
		target->receive_wound("qi", damage/10);
		msg += HIR"$nֻ������һ��һ����Ѫ�������������\n"NOR;
	} else if (random(me->query("combat_exp")) > target->query("combat_exp")/3) {
		target->receive_damage("qi", damage/10);
		target->receive_wound("qi", damage/20);
		msg += HIR"$n����һ��������ס������һƴ֮�£� ���в�������һ˿��Ѫ��\n"NOR;
	} else {
		target->add("neili", -600);
		msg += HIY"$Nֻ��$n������񣬾��������޷����롣\n"NOR;
	}
	message_combatd(msg, me, target);
}
else {	
	if (random(me->query("neili")) > target->query("neili")) {
		target->receive_damage("qi", damage/5);
		target->receive_wound("qi", damage/7);
		msg += HIR"$nֻ������һ��һ����Ѫ�������������\n"NOR;
	} else if (me->query("neili") > target->query("neili") / 2) {
		target->receive_damage("qi", damage/12);
		target->receive_wound("qi", damage/12);
		msg += HIR"$n����һ��������ס������һƴ֮�£� ���в�������һ˿��Ѫ��\n"NOR;
	} else {
		target->add("neili", -600);
		msg += HIY"$Nֻ��$n������񣬾��������޷����롣\n"NOR;
	}
	message_combatd(msg, me, target);
	return 1;
}
}
