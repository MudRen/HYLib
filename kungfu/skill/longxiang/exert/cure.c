// lifeheal.c

#include <ansi.h>

int exert(object me, object target)
{
	if( !target || target == me)
		return notify_fail("��Ҫ������Ϊ˭���ƣ�\n");

	if( me->is_fighting() || target->is_fighting() || !living(target))
		return notify_fail("ս�����޷��˹����ƣ�\n");
	if( environment(me)->query("no_fight") )
		return notify_fail("���ﲻ�ܹ�������! \n");

	if( (int)me->query("max_neili") < 1000 )
		return notify_fail("���������Ϊ������\n");

	if( (int)me->query("neili") < 500 )
		return notify_fail("�������������\n");
        if( !target->query_condition("dashouyin"))
                return notify_fail("�Է���û�д���ӡ���ˣ��㲻��Ϊ�������ˡ�\n");

//        if( (int)me->query_skill("medicine", 1) < 40 )
//                return notify_fail("�㱾������ĵȼ��������޷�Ϊ�������ˡ�\n");
        if( (int)me->query_skill("longxiang", 1) < 80 )
                return notify_fail("���ڹ��ȼ��������޷�Ϊ�������ˡ�\n");

	if( (int)target->query("eff_qi") >= (int)target->query("max_qi") / 2 )
		return notify_fail( target->name()+"�������˲��Ǻ��أ�������ٹ۲�һ�£�\n");

	else {message_vision(
                HIY "$N�������ڷ�ħ���ԣ�����������$n���ģ������ؽ���������$n����......\n"
                   "$n�漴�³�һ����Ѫ����ɫ������������ˣ��������˺ܴ�ĺ�ת��\n" NOR,
		me, target );
	}
	target->receive_curing("qi", 10 + (int)me->query_skill("force")/2 );
	target->add("qi", 10 + (int)me->query_skill("force")/2 );
    if( userp(target) && (int)target->query("qi") > (int)target->query("eff_qi") ) target->set("qi", (int)target->query("eff_qi"));
    if( !userp(target) && (int)target->query("qi") > (int)target->query("max_qi")*5 ) target->set("qi", (int)target->query("max_qi"));
        target->clear_condition("dashouyin");
	me->add("neili", -300);

	return 1;
}
