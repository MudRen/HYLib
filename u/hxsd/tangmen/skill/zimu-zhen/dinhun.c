// ���� ��ĸ�����⼼

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
		return notify_fail("�����꡹ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "throwing")
			return notify_fail("��ʹ�õ��������ԡ�\n");

	if( target->is_busy() )
		return notify_fail(target->name() + "�Ѿ���־��㱣��ŵ�������.\n");
		
	if( (int)me->query_skill("zimu-zhen", 1) < 30 )
		return notify_fail("�����ĸ�뷨������죬����ʹ�á����꡹��\n");

	if( (int)me->query_skill("biyun-xinfa", 1) < 60 )
                return notify_fail("��ı����ķ������ߡ�\n");

        if( (int)me->query("neili", 1) < 300 )
                return notify_fail("����������̫����\n");


	msg = HIG "$N˫ĿͻȻ���������̹�,��ָ�ڲ��ײ����΢΢һ��,һ������������Ϣ����$nü�ġ�\n"NOR;

	me->start_busy(1);
	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
		msg += HIR " ���$p��$P�ġ����꡹������ţ�˲����־��ʼ�Ժ�������\n" NOR;
                target->start_busy( (int)me->query_skill("zimu-zhen") / 20 );
        target->apply_condition("tmzhuihun_poison", 10);

	} else {
		msg += "����$p��ǧ��һ��֮������������һ����\n" NOR;
	}
	message_vision(msg, me, target);

	return 1;
}
