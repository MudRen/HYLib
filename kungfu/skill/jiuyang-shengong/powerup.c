// powerup.c �����񹦼���

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
	int skill;

	if ( !wizardp(this_player()) && (me->query("family/family_name") != "����"))
		return notify_fail("�㲻�����̽��ڲ���ʹ�þ����񹦡�\n");
//		 		    �����񹦲�����, �����ֵ��Ӳ���, �治֪��������ôѧ���!\n
//				    ����, ����, �����ڵ��з����Ƿ���Ҫ�ٺú�ѧһѧ.\n");
	if( target != me ) 
		return notify_fail("��ֻ���þ������������Լ���ս������\n");

	if( (int)me->query("neili") < 100  ) 
		return notify_fail("�������������\n");
	if( (int)me->query_temp("powerup") ) 
		return notify_fail("���Ѿ����˹����ˡ�\n");

	skill = me->query_skill("force");
	me->add("neili", -100);
	me->receive_damage("qi", 0);

	message_combatd(
	HIR "$N΢һ������������񹦣�ȫ��ǽڷ���һ�󱬶��������, ��ȫ��Ǳ�ܾ�������\n" NOR, me);
me->clear_condition("xuanming_poison");
me->clear_condition("cold_poison");
me->clear_condition("xscold_poison");
me->clear_condition("ice_poison");
me->clear_condition("iceshock");

	me->add_temp("apply/attack", skill/3);
	me->add_temp("apply/dodge", skill/3);
	me->set_temp("powerup", 1);

	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/3 :), skill);

	if( me->is_fighting() ) me->start_busy(3);

	return 1;
}

void remove_effect(object me, int amount)
{
   int skill;
   skill = me->query_skill("force");

   if ( (int)me->query_temp("powerup") ) {
   me->add_temp("apply/attack", -skill/3);
   me->add_temp("apply/dodge", -skill/3);
	me->delete_temp("powerup");
	tell_object(me, "��ľ�����������ϣ��������ջص��\n");}
}
