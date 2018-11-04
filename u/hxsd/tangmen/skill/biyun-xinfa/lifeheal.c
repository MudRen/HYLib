// lifeheal.c

#include <ansi.h>

int exert(object me, object target)
{
	if( !target )
		return notify_fail("��Ҫ������Ϊ˭���ˣ�\n");

	if( me->is_fighting() || target->is_fighting())
		return notify_fail("ս�����޷��˹����ˣ�\n");

	if(target == me)
		return notify_fail("��û��Ϊ�Լ����˵�������\n");

	if( (int)me->query("max_neili") < 400 )
		return notify_fail("���������Ϊ������\n");

	if( (int)me->query("neili") < 150 )
		return notify_fail("�������������\n");

	if( (int)target->query("eff_qi") < (int)target->query("max_qi") / 5 )
		return notify_fail( target->name() +
			"�Ѿ����˹��أ����ܲ�����������𵴣�\n");

	message_vision(
		HIG "$N�������������ڹ�������������$n���ģ������ؽ���������$n����....\n\n"
		"���˲��ã�$N��ͷ��ð������ĺ��飬$n�³�һ����Ѫ����ɫ������������ˡ�\n" NOR,
		me, target );

	target->receive_curing("qi", 10 + (int)me->query_skill("force")/3 );
	target->add("qi", 10 + (int)me->query_skill("force")/3 );
	if( (int)target->query("qi") > (int)target->query("eff_qi") ) target->set("qi", (int)target->query("eff_qi"));

	if ((int)me->query_skill("biyun-xinfa", 1) > 150)
{
	if (target->query_condition("zm_poison"))
		target->apply_condition("zm_poison",0);
	else if (target->query_condition("tmpili_poison"))
		target->apply_condition("tmpili_poison",0);
	else if (target->query_condition("tmzhuihun_poison"))
		target->apply_condition("tmzhuihun_poison",0);
        else if (target->query_condition("snake_poison"))
        {          target->clear_condition("snake_poison");}
        else if (target->query_condition("wugong_poison"))
        {          target->clear_condition("wugong_poison");}
        else if (target->query_condition("zhizhu_poison"))
        {          target->clear_condition("zhizhu_poison");}
        else if (target->query_condition("xiezi_poison"))
        {          me->clear_condition("xiezi_poison");}
        else if (target->query_condition("chanchu_poison"))
        {          target->clear_condition("chanchu_poison");}
	me->add("neili", -100);
}
	me->add("neili", -100);
	me->set("jiali", 0);
                me->start_busy(5);
                target->start_busy(5);
	return 1;
}
