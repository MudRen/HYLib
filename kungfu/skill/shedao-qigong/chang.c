
#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	int skill;
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("���ɷ�ֻ����ս����ʹ�á�\n");

	if( (int)me->query_skill("shedao-qigong", 1) < 100 )
		return notify_fail("����ߵ��湦������죬����ʹ�ó��ɷ���\n");

	if ((int)me->query_skill("shenlong-xinfa",1) < 10)
		return notify_fail("��������ķ���򲻹���\n");

	if( (int)me->query("neili") < 300 )
		return notify_fail("���Ѿ����þ�ƣ����,���������ˡ�\n");

	if( (int)me->query_temp("chang") > 4 )
		return notify_fail("���Ѿ�����̫����,�����ٳ��ˡ�\n");

	skill = me->query_skill("force");

	me->add("neili", -200);

	message_combatd(
        HIR "ֻ��$N���������дʣ����֮���书�����\n" NOR, me);

	me->add_temp("apply/attack", 20);
	me->add_temp("apply/dodge", 20);
	me->add_temp("apply/defense", 20);
	me->add_temp("apply/armor", 20);
	me->add_temp("apply/damage", 20);
	me->add_temp("chang", 1);

	return 1;
}
