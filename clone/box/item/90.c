// z-dan.c
// ����(lywin)��������������

#include <ansi.h>
inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name("���������", ({"gdan4", "dan4"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�ź�������ࡣ\n");
		set("value", 15000);
	}
	setup();
}

int do_eat(string arg)
{
        object me = this_player();
 	if (!id(arg))
	return notify_fail("��Ҫ��ʲô��\n");

	if ( me->query("max_neili") < 600 )
	{
		me->add("max_neili", -1);
		message_vision(HIR "$N����һ�ź�������ֻ࣬����ͷ�ؽ��ᣬҡҡ������ԭ������������ҩЧ�ʵ��䷴��\n" NOR, me);
	}
            else if ( (int)me->query_condition("medicine") > 0 )
	{
		me->add("max_neili", -5);
		message_vision(HIR "$N����һ�ź�������ֻ࣬����ͷ�ؽ��ᣬҡҡ������ԭ����ʳ̫��̫�࣬ҩЧ�ʵ��䷴��\n" NOR, me);
	}
	else
	{
        me->add("jing", 1000);
        me->add("max_neili", 1);
        message_vision(HIG "$N����һ�ź�������ֻ࣬������������ԴԴ��������ľ������!\n" NOR, me);
	}

        me->apply_condition("medicine", 60);
	
	destruct(this_object());
	return 1;
}