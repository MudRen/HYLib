// heal.c

#include <ansi.h>

int exert(object me, object target)
{
	if( me->is_fighting() )
		return notify_fail("ս�����˹����ˣ�������\n");

	if ((int)me->query_skill("wudu-shengong", 1) < 30)
		return notify_fail("����嶾����Ϊ��������\n");
	if( (int)me->query("neili") < 50 ) 
		return notify_fail("�������������\n");
       
	if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 3 )
		return notify_fail("���Ѿ����˹��أ�ֻ��һ��������������Σ�գ�\n");

	write( HIW "��ȫ����ɣ��嶾����תȫ��\n" NOR);
	message("vision",
		HIW + me->name() + "����ֳ�һƬ���죬��ͷ���߳�ϸϸ�ĺ��顣\n" NOR,
		environment(me), me);
       me->set_temp("nopoison", 1);
       me->apply_condition("yf_poison",0);
       me->apply_condition("nx_poison",0);
       me->apply_condition("x2_poison",0);
       me->apply_condition("xx_poison",0);
       me->apply_condition("ice_poison",0);
       me->apply_condition("ss_poison",0);
	write( HIW "���������һ�������������չ鵤��о�����ö��ˡ�\n" NOR);
	me->receive_curing("qi", 10 + (int)me->query_skill("force")/5 );
	me->add("neili", -50);
	me->set("jiali", 0);
	return 1;
}
