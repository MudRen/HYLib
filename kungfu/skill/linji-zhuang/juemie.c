// riyun.c

#include <ansi.h>

int exert(object me)
{	
	int nb, nx, nh, improve;
	nx = (int)me->query("max_qi", 1);
	nb = (int)me->query("eff_jing", 1);
	nh = (int)me->query_skill("linji-zhuang", 1);

	if ((int)me->query_skill("linji-zhuang", 1) < 300)
		return notify_fail("����ټ�ʮ��ׯ��Ϊ��������\n");

	if( (int)me->query("neili") < (int)me->query("max_neili")/3 )
		return notify_fail("�������������\n");

	write(RED"���������죬�������¶�ׯ����������������Ǳ����
������������ض�����̩��������϶��Ҿ����������֮���ʱ����!\n"NOR);

	message_vision(HIR"ֻ��$N���Ϻ��ʱ��ʱ�֡��������磡��\n"NOR, me);
me->set("qi",me->query("max_qi")*3);
me->set("eff_qi",me->query("max_qi")*3);
me->set("jing",me->query("max_jing")*3);
me->set("eff_jing",me->query("max_jing")*3);
me->add("neili",-me->query("neili")/2);
me->start_busy(3);
return 1;
}
