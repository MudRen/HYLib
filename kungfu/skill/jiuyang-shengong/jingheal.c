// jingheal.c

#include <ansi.h>

int exert(object me, object target)
{
	//if ( !wizardp(this_player()) )
	//	return notify_fail("����Ȩ���о������ƣ�\n");

	if( !target )
		return notify_fail("��Ҫ������Ϊ˭���ˣ�\n");

        if(me->is_busy())
        return notify_fail("��������æ��\n");

	if( me->is_fighting() || target->is_fighting())
		return notify_fail("ս�����޷��˹����ˣ�\n");

	if( (int)me->query("max_neili") < 300 )
		return notify_fail("���������Ϊ������\n");

	if( (int)target->query("max_neili") < 300 )
		return notify_fail("�Է���������Ϊ������\n");

	if( (int)me->query("neili") < (int)me->query("max_neili")/9)
		return notify_fail("�������������\n");

	if( (int)target->query("neili") < (int)target->query("max_neili")/9)
		return notify_fail("�Է�������������\n");

	message_vision(
		HIY "$N�������������ڹ�������������$n���ģ������ؽ���������$n����....\n\n"
		"���˲��ã�$N��ͷ��ð������ĺ��飬$n�³�һ����Ѫ����ɫ������������ˡ�\n" NOR,
		me, target );

	target->receive_curing("jing", 10 + (int)me->query_skill("force")/3 );
	target->add("jing", 10 + (int)me->query_skill("force")/3 );
target->clear_condition("xuanming_poison");
target->clear_condition("cold_poison");
target->clear_condition("xscold_poison");
target->clear_condition("ice_poison");
target->clear_condition("iceshock");

	if( (int)target->query("jing") > (int)target->query("eff_jing") )
		target->set("jing", (int)target->query("eff_jing"));

	me->add("neili", -(int)me->query("max_neili")/10);
	me->set("jiali", 0);
	me->start_busy(3);
        target->start_busy(3);
        target->add("neili", -(int)me->query("max_neili")/10);
	return 1;
}

