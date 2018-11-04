// qudu.c

#include <ansi.h>

int exert(object me, object target)
{
	int con1, con2, con3;
	con1 = me->query_condition("snake_poison");
	con2 = me->query_condition("scorpion_poison");
	con3 = me->query_condition("xx_poison");

	if( me->is_fighting() )
		return notify_fail("ս�����˹�������������\n");

	if( (int)me->query("neili") < 50 )
		return notify_fail("�������������\n");

	if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
		return notify_fail("���Ѿ����˹��أ�ֻ��һ��������������Σ�գ�\n");

	if ((int)me->query_skill("hamagong", 1) < 20)
		return notify_fail("��ĸ�󡹦��Ϊ��������\n");

	if (con1 > 0) 
	{
		if (con1 < 3)
		{
			me->apply_condition("snake_poison", 0);
			write( HIW "���˹����߶������ɾ��ˡ�\n" NOR);
		}
		else
		{
			me->apply_condition("snake_poison", con1 - 4);
			write( HIW "��ȫ����ɣ���������ʼ�˹������߶���\n" NOR);
		}
		message("vision", 
	HIY+me->name()+"�³�һ�ڽ�Ӳӵ���Ѫ��һ�εκ�Ѫ���˿�����������\n" NOR,
		environment(me), me);
	}
	else
	if (con2 > 0)
	{
		if (con2 < 3)
		{
			me->apply_condition("scorpion_poison", 0);
			write( HIW "���˹���Ы�������ɾ��ˡ�\n" NOR);
		}
		else
		{
			me->apply_condition("scorpion_poison", con2 - 4);
			write( HIW "��ȫ����ɣ���������ʼ�˹�����Ы����\n" NOR);
		}
		message("vision", 
	HIY+me->name()+"�³�һ�ڽ�Ӳӵ���Ѫ��һ�ε�����Ѫ����˿�����������\n" NOR,
		environment(me), me);
	}
	else
	if (con3 > 0)
	{
		if ((int)me->query_skill("hamagong", 1) < 30)
			return notify_fail("��ĸ�󡹦��Ϊ��������\n");
		if (con3 < 3)
		{
			me->apply_condition("xx_poison", 0);
			write( HIW "���˹��������ƶ������ɾ��ˡ�\n" NOR);
		}
		else
		{
			me->apply_condition("xx_poison", con3 - 4);
			write( HIW "��ȫ����ɣ���������ʼ�˹����������ƶ���\n" NOR);
		}
		message("vision", 
	HIY+me->name()+"�³�һ����Ѫ���԰׵����϶��˵�Ѫɫ��\n" NOR,
		environment(me), me);
	}
	else write( HIW "�����û�ж��ɡ�\n" NOR);

	me->add("neili", -50);
	me->set("jiali", 0);
	me->start_busy(4);

	return 1;
}
