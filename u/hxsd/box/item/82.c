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
	set_name("��ת������", ({"gdan2", "dan2"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�ž�ת�����衣\n");
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
		message_vision(HIR "$N����һ�ž�ת�����裬ֻ����ͷ�ؽ��ᣬҡҡ������ԭ������������ҩЧ�ʵ��䷴��\n" NOR, me);
	}
            else if ( (int)me->query_condition("medicine") > 0 )
	{
		me->add("max_neili", -5);
		message_vision(HIR "$N����һ�ž�ת�����裬ֻ����ͷ�ؽ��ᣬҡҡ������ԭ����ʳ̫��̫�࣬ҩЧ�ʵ��䷴��\n" NOR, me);
	}
	else
	{
        me->add_temp("apply/damage", 100);
        me->add("max_neili", 1);
        message_vision(HIG "$N����һ�ž�ת�����裬ֻ������������ԴԴ���������ɱ���������!\n" NOR, me);
	}

        me->apply_condition("medicine", 120);

	destruct(this_object());
	return 1;
}