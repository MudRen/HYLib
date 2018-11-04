// /u/jpei/thd/obj/sancai-dan.c ���ž۾��� 

#include <ansi.h>

inherit ITEM;

void setup() {}

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name("���ž۾���", ({"sancai dan", "dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ������ɫ�ĵ�ҩ��͸��һ��Ũ�صĻ��㡣\n");
		set("value", 100);
                set("no_drop", 1);
                set("no_get", 1);
	}
	setup();
}

int do_eat(string arg)
{
	object me = this_player();

	if (!id(arg))
		return notify_fail("��Ҫ��ʲô��\n");

	if ( me->query("family/family_name") != "�һ���" )
	{
/*		if (me->add("max_jingli", -10) < 0)
			me->set("max_jingli", 0);
		if (me->add("eff_jingli", -10) < 0)
			me->set("eff_jingli", 0);
		message_vision(HIR "$N����һ�����ž۾�����ֻ����ͷʹ���ѣ�ԭ������һ�ż�ҩ��\n" NOR, me);
		me->unconcious();
		destruct(this_object());
*/    
		message_vision(HIR "�����ڹ���������ҩ�㲻�����ԣ�\n" NOR, me);
		return 1;
	}
	if ( (int)me->query("max_jingli" ) < 200) {
		message_vision(HIR "������������ҩ�����к����ˡ�\n" NOR, me);
		return 1;
	}
	

	if ( (int)me->query_condition("jingli_drug" ) > 0 )
	{
		if (me->add("max_jingli", -1) < 0)
			me->set("max_jingli", 0);
		if (me->add("eff_jingli", -1) < 0)
			me->set("eff_jingli", 0);
		message_vision(HIR "$N����һ�����ž۾�����ֻ����ͷ��Ŀѣ���������ԣ�ԭ����ҩ��ʳ̫��̫�࣬ҩЧ�ʵ��䷴��\n" NOR, me);
	}
	else
	{
		me->add("max_jingli", 1);
		me->add("eff_jingli", 1);
		message_vision(HIG "$N����һ�����ž۾�����ֻ�������ھ������磬�ƺ���ʹ����ľ���\n" NOR, me);
		me->apply_condition("jingli_drug", 60);
	}
	destruct(this_object());
	return 1;
}
