
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

	if( (int)me->query_skill("shedao-qigong", 1) < 150 )
		return notify_fail("����ߵ��湦������죬����ʹ�ó��ɷ���\n");

	if ((int)me->query_skill("shenlong-xinfa",1) < 10)
		return notify_fail("��������ķ���򲻹���\n");

	if((int)me->query_temp("apply/attack")<=0||(int)me->query_temp("apply/dodge") <=0||(int)me->query_temp("apply/defense") <=0 )
		return notify_fail("��Ŀǰս����̫�ͣ������ٻָ������ˡ�\n");

	if( (int)me->query_temp("chang2") > 4  )
		return notify_fail("���Ѿ�����̫���ˣ������ٳ��ˡ�\n");

	message_combatd(HIR "ֻ��$N���������дʣ����֮���������ǣ�\n" NOR, me);
//	me->add_temp("apply/attack", -1);
//	me->add_temp("apply/dodge", -1);
//	me->add_temp("apply/defense", -1);
	me->add_temp("chang2", 1);
	me->add("neili", 1000);

	return 1;
}
