// powerup.c �����ķ�����

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
	int skill;

	if( target != me ) 
		return notify_fail("��ֻ���ñ����ķ��������Լ���ս������\n");

	if( (int)me->query("neili") < 100  ) 
		return notify_fail("�������������\n");
	if( (int)me->query_temp("powerup") ) 
		return notify_fail("���Ѿ����˹����ˡ�\n");

	skill = me->query_skill("force");
	me->add("neili", -100);
	me->receive_damage("qi", 0);

	message_vision(
	HIG "$N΢һ������������ķ������Ϸ���һ�����ɫ,����������ķ������\n" NOR, me);

	me->add_temp("apply/attack", skill/5);
	me->add_temp("apply/dodge", skill/5);
	me->add_temp("apply/defense",skill/5);
	me->set_temp("powerup",1);

       me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/5 :), skill/3);

       if( me->is_fighting() ) me->start_busy(1);

	return 1;
}

void remove_effect(object me, int amount)
{
  if ( (int)me->query_temp("powerup") ) {
	me->add_temp("apply/attack", - amount);
	me->add_temp("apply/dodge", - amount);
	me->add_temp("apply/defense", - amount);
	me->delete_temp("powerup");
	tell_object(me, "��ı����ķ�������ϣ��������ջص��\n");}
}
