// counterattack.c
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
		return notify_fail("��ճ�־���ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( target->is_busy() )
		return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɣ�\n");
        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                        return notify_fail("��ʹ�õ��������ԡ�\n");
	if( (int)me->query("neili") < 500  ) 
		return notify_fail("�������������\n");
        me->add("neili",-200);
	msg = CYN "$Nʹ�����Ž����еġ�ճ���־�����ͼ����$n�Ĺ��ƣ�";
	me->start_busy(1);
	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
		msg += "���$p��$P���˸����ֲ�����\n" NOR;
		target->start_busy( (int)me->query_skill("three-sword") / 50 + 2);
	} else {
		msg += "����$p������$P����ͼ����û���ϵ���\n" NOR;
	}
	message_vision(msg, me, target);

	return 1;
}
