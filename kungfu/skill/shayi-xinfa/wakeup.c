// wakeup ����

#include <ansi.h>

int exert(object me, object target)
{
    if( !objectp(target) )
		return notify_fail("��Ҫ��������˭��\n");

	if( me->is_fighting() || target->is_fighting())
		return notify_fail("ս�����޷����ˣ�\n");

	if( (int)me->query("max_neili") < 1000 )
		return notify_fail("���������Ϊ������\n");


	if( (int)me->query("neili") < 100 )
		return notify_fail("�������������\n");

	if ((int)me->query_skill("shayi-xinfa", 1) < 250)
		return notify_fail("���ɱ���ķ���Ϊ��������\n");

        if( living(target) )
		return notify_fail( target->name() +
			"��û�л��Բ��Ѱ���\n");

	message_vision(
          HIG "$N������ɱ��������������$n���ģ��Ծ���֮�Ľ���������$n����......\n\n"
		"$nֻ��һ������ԴԴ�������������ڣ�˲������ȫ�����Ѩλ��$n�³�һ\n\n"
		"����Ѫ������������\n" NOR,
		me, target );

	target->receive_curing("qi", 10 + (int)me->query_skill("force")/4 );
	target->add("qi", 10 + (int)me->query_skill("force")/4 );
  target->remove_call_out("revive");
  target->revive();
  target->reincarnate();

	me->add("neili", -800);
	me->set("jiali", 0);
        me->start_busy(10);
	return 1;
}
