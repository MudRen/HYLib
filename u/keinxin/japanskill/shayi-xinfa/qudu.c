// qudu.c

#include <ansi.h>

int exert(object me, object target)
{
	int con1, con2, con3;

	if( me->is_fighting() )
		return notify_fail("ս�����˹�������������\n");

	if( (int)me->query("neili") < 50 )
		return notify_fail("�������������\n");

	if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
		return notify_fail("���Ѿ����˹��أ�ֻ��һ��������������Σ�գ�\n");

	if ((int)me->query_skill("shayi-xinfa", 1) < 150)
		return notify_fail("���ɱ���ķ���Ϊ��������\n");



	if (me->query_condition("drunk"))
		me->apply_condition("drunk",0);
	else if (me->query_condition("flower_poison"))
		me->apply_condition("flower_poison",0);
	else if (me->query_condition("ice_poison"))
		me->apply_condition("ice_poison",0);
	else if (me->query_condition("rose_poison"))
		me->apply_condition("rose_poison",0);
	else if (me->query_condition("scorpion_poison"))
		me->apply_condition("scorpion_poison",0);
	else if (me->query_condition("snake_poison"))
		me->apply_condition("snake_poison",0);
        else if (me->query_condition("snake_poison"))
        {          me->clear_condition("snake_poison");}
        else if (me->query_condition("wugong_poison"))
        {          me->clear_condition("wugong_poison");}
        else if (me->query_condition("zhizhu_poison"))
        {          me->clear_condition("zhizhu_poison");}
        else if (me->query_condition("xiezi_poison"))
        {          me->clear_condition("xiezi_poison");}
        else if (me->query_condition("chanchu_poison"))
        {          me->clear_condition("chanchu_poison");}
        else if (me->query_condition("qishang_poison"))
        {          me->clear_condition("qishang_poison");}
        else if (me->query_condition("flower_poison"))
        {          me->clear_condition("flower_poison");}
        else if (me->query_condition("yufeng_poison"))
        {          me->clear_condition("yufeng_poison");}
        else if (me->query_condition("anqi_poison"))
        {          me->clear_condition("anqi_poison");}
       else if (me->query_condition("yf_poison"))
        {          me->clear_condition("yf_poison");}
else 	return notify_fail("������û��ʲôɱ���ķ��ܽ�Ķ�!\n");
	write( HIR "���ɱ���ķ����ӵ��˼��ޣ����ڵĶ�����ʧ����ɱ���С�\n" NOR);
		message("vision", 
	HIY+me->name()+"����ɱ����������ɱ����Ȼ��������ɫ�ģ�\n" NOR,
		environment(me), me);

	me->add("neili", -50);
	me->set("jiali", 0);
	me->start_busy(4);

	return 1;
}
