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

	if ((int)me->query_skill("biyun-xinfa", 1) < 150)
		return notify_fail("��ı����ķ���Ϊ��������\n");



	if (me->query_condition("zm_poison"))
		me->apply_condition("zm_poison",0);
	else if (me->query_condition("tmpili_poison"))
		me->apply_condition("tmpili_poison",0);
	else if (me->query_condition("tmzhuihun_poison"))
		me->apply_condition("tmzhuihun_poison",0);
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
       else 	return notify_fail("������û��ʲô�����ڹ��ܽ�Ķ�!\n");
	write( HIB "���������ŵı����ķ����³���һ�ڱ�ɫ��Ѫҹ!!�⿪�����ϵĶ���!\n" NOR);
		message("vision", 
	HIB+me->name()+"�³���һ�ڱ�ɫ��Ѫҹ!!\n" NOR,
		environment(me), me);

	me->add("neili", -50);
	me->set("jiali", 0);
	me->start_busy(2);

	return 1;
}
