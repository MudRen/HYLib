// reserve.c ����

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int a_amount, int d_amount);

int exert(object me, object target)
{
	object weapon;
	int skill;
	string msg;

	if( (int)me->query_skill("yunlong-shengong", 1) < 100 )
		return notify_fail("��������񹦲�����죬��������\n");

	if( (int)me->query("neili") < 200  ) 
		return notify_fail("�������������\n");

	if( (int)me->query_temp("yl_dzjm") ) 
		return notify_fail("���Ѿ����������ˡ�\n");

	skill = me->query_skill("yunlong-shengong",1);
	msg = HIR  "$N�߸��������������񹦣���ʱ��Ϣ�������Ṧ������\n"NOR;
	message_combatd(msg, me, target);

	me->add_temp("apply/attack", skill/5);
	me->add_temp("apply/dodge", skill/2);
	me->set_temp("yl_dzjm", 1);

	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/5, skill/2 :), skill);

	me->add("neili", -100);
	if( me->is_fighting() ) me->start_busy(2);

	return 1;
}

void remove_effect(object me, int a_amount, int d_amount)
{
int skill;
	skill = me->query_skill("yunlong-shengong",1);
	me->add_temp("apply/attack", -skill/5);
	me->add_temp("apply/dodge", -skill/2);
	me->delete_temp("yl_dzjm");
	tell_object(me, HIR "�����Ϣ������ֻ��һԾ���𣬽������ջص��\n");
}
