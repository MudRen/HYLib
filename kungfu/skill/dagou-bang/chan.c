// chan.c �򹷰����������־�

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon;
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�������־�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "staff")
			return notify_fail("��ʹ�õ��������ԡ�\n");

	if( target->is_busy() )
		return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɢ�\n");
		
	if( (int)me->query("neili") < 100  ) 
		return notify_fail("�������������\n");

	if( (int)me->query_skill("dagou-bang",1) < 100 )
		return notify_fail("��Ĵ򹷰���������죬����ʹ�á������־���\n");
        if (me->query_skill("huntian-qigong", 1)<70)
                return notify_fail("��ı����ڹ����δ������\n");

	msg = HIG "$Nʹ���򹷰����������־�����ͷ�ڵ������㣬���಻��������$n��С�Ⱥͽ��ס�\n";

	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 ) {
		msg += HIR " ���$p��$P���ı�����ͣ����æ���ң�\n" NOR;
		target->start_busy( (int)me->query_skill("dagou-bang",1) / 50 +3 );
	} else {
		msg += "����$p������$P����ͼ���򶨽��У�һ˿���ҡ�\n" NOR;
	me->start_busy(2);
}
	message_combatd(msg, me, target);
	me->add("neili", - 60);
	if(!target->is_fighting(me)) target->fight_ob(me);
	return 1;
}
