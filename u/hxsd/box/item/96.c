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
	set_name("���Ʊ�����", ({"gdan5", "dan5"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�����Ʊ�������\n");
		set("value", 15000);
	}
	setup();
}

int do_eat(string arg)
{
        object me = this_player();
 	if (!id(arg))
	return notify_fail("��Ҫ��ʲô��\n");

	if ( me->query("max_neili") < 400 )
	{
		me->add("max_neili", -1);
		message_vision(HIR "$N����һ��ţ��Ѫ�ߵ���ֻ����ͷ�ؽ��ᣬҡҡ������ԭ������������ҩЧ�ʵ��䷴��\n" NOR, me);
	}
            else if ( (int)me->query_condition("medicine") > 0 )
	{
		me->add("max_neili", -5);
		message_vision(HIR "$N����һ��ţ��Ѫ�ߵ���ֻ����ͷ�ؽ��ᣬҡҡ������ԭ����ʳ̫��̫�࣬ҩЧ�ʵ��䷴��\n" NOR, me);
	}
	else
	{
        me->add("qi", 800);
        message_vision(HIG "$N����һ��ţ��Ѫ�ߵ���ֻ������������ԴԴ����������������!\n" NOR, me);
	}

        me->apply_condition("medicine", 40);
	
	destruct(this_object());
	return 1;
}