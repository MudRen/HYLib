// regenerate.c

//inherit SSERVER;

int exert(object me, object target)
{
	int j;
	if (target != me) 
		return notify_fail("��ֻ�����ڹ��ָ��Լ��ľ�����\n");

	if( me->is_busy() )
		return notify_fail("����һ��������û����ɣ�\n");
	
	if ((int)me->query("neili") < 35)
		return notify_fail("�������������\n");
	j = (int)me->query("eff_jing") - (int)me->query("jing");
	if (j < 10)
		return notify_fail("�����ھ�����ʢ��\n");

	me->add("neili", -30);
if ((int)me->query("eff_jing") <= (int)me->query("max_jing"))
{
	me->receive_heal("jing", (int)me->query_skill("force") / 2);
}
if ((int)me->query("jing") <= (int)me->query("eff_jing"))
{
	me->add("jing", (int)me->query_skill("force") / 2);	
}        message_combatd("$N�������˼����������������ö��ˡ�\n", me);
//        me->start_busy(1);

        if( me->is_fighting() ) me->start_busy(2);
	
	return 1;
}

