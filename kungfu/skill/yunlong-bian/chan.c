// chan.c �����޷� ���־�

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
    object weapon = me->query_temp("weapon");  
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("ǣ�ƹ���ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( (int)me->query_skill("yunlong-bian",1) < 50)
		return notify_fail("��ġ������޷�������̫ǳ��ʹ���ˡ������־���\n");

	if( (int)me->query_skill("yunlong-shengong", 1) < 50 )
		return notify_fail("��������񹦲����ߣ��������������˵С�\n");

    if (!weapon || weapon->query("skill_type") != "whip")
        return notify_fail("��ʹ�õ��������ԡ�\n");
        if( (int)me->query("neili", 1) < 300 )
                return notify_fail("�������������㣡\n");     

	if( target->is_busy() )
		return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɢ�\n");

	msg = CYN "$Nʹ�������޷��������־������ӳ�����ͼ��$n��ȫ���ס��\n";

	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 ) {
		msg += "���$p��$P���˸����ֲ���\n" NOR;
		target->start_busy( (int)me->query_skill("yunlong-bian") / 50 + 2);
	} else {
		msg += "����$p������$P����ͼ����û���ϵ���\n" NOR;
		me->start_busy(2);
	}
me->add("neili", -100);
	message_combatd(msg, me, target);
	if(!target->is_fighting(me)) target->fight_ob(me);
	return 1;
}
