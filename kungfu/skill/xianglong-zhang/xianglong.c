// reserve.c ����

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int a_amount, int d_amount);

int perform(object me, object target)
{
	object weapon;
	int skill;
	string msg;

	if( (int)me->query_temp("xianglong") ) 
		return notify_fail("���Ѿ����˹����ˡ�\n");
	if( !me->is_fighting() )
		return notify_fail("������ֻ����ս����ʹ�á�\n");

        if (me->query_skill("huntian-qigong", 1)<70)
                return notify_fail("��ı����ڹ����δ������\n");

	if( (int)me->query("neili") < 300  ) 
		return notify_fail("�������������\n");

       skill = me->query_skill("xianglong-zhang",1);
	message_combatd( HIR "$N����һ�������������󷨣����ԽսԽ�£�\n" NOR, me);

	me->set_temp("xianglong", 1);

//	message_combatd(msg, me, target);

	me->add_temp("apply/attack", skill/4);
	me->add_temp("apply/dodge", skill/4);

	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/6, skill/4 :), skill);

	me->add("neili", -100);

	return 1;
}

void remove_effect(object me, int a_amount, int d_amount)
{
int skill;
	skill = me->query_skill("xianglong-zhang",1);
	me->add_temp("apply/attack", -d_amount);
	me->add_temp("apply/dodge", -d_amount);
	me->delete_temp("xianglong");
	tell_object(me, CYN "��Ľ�����������ϣ��������ջص��\n");
}
