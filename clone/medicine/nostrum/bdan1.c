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
	set_name("������", ({"jingqi wan", "dan1"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�ž����衣\n");
		set("value", 3000);
	set("lev", 1+random(3));
	}
	setup();
}

int do_eat(string arg)
{
        object me = this_player();
 	if (!id(arg))
	return notify_fail("��Ҫ��ʲô��\n");

	if ( me->query("max_neili") < 200 )
	{
		me->add("max_neili", -1);
		message_vision(HIR "$N����һ�ž����裬ֻ����ͷ�ؽ��ᣬҡҡ������ԭ������������ҩЧ�ʵ��䷴��\n" NOR, me);
	}
            else if ( (int)me->query_condition("medicine") > 0 )
	{
		me->add("max_neili", -5);
		message_vision(HIR "$N����һ�ž����裬ֻ����ͷ�ؽ��ᣬҡҡ������ԭ����ʳ̫��̫�࣬ҩЧ�ʵ��䷴��\n" NOR, me);
	}
	else
	{
        me->add("qi", 200);
        me->add("jing", 200);
        message_vision(HIG "$N����һ�ž����裬ֻ�������ڵľ��������˲���!\n" NOR, me);
	}

        me->apply_condition("medicine", 20);
	
	destruct(this_object());
	return 1;
}