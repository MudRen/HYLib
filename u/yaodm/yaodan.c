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
	set_name("�β�������", ({"yao dan", "yaodan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ���β��ⶾ�衣\n");
		set("value", 5000);
	}
	setup();
}

int do_eat(string arg)
{
        object me = this_player();
        	if (!id(arg))
	return notify_fail("��Ҫ��ʲô��\n");

	if ( me->query("max_neili") < 10 )
	{
		message_vision(HIR "$N����һ���β������裬ֻ����ͷ�ؽ��ᣬҡҡ������ԭ������������ҩЧ�ʵ��䷴��\n" NOR, me);
	}
            else if ( (int)me->query_condition("medicine") > 0 )
	{
		message_vision(HIR "$N����һ���β������裬ֻ����ͷ�ؽ��ᣬҡҡ������ԭ����ʳ̫��̫�࣬ҩЧ�ʵ��䷴��\n" NOR, me);
	}
	else
	{
	me->apply_condition("ill_zhongshu", 0);
        me->apply_condition("ill_fashao", 0);
	me->apply_condition("ill_kesou", 0);
        me->apply_condition("ill_shanghan", 0);
	me->apply_condition("ill_dongshang", 0);
        message_vision(HIC "$N����һ���β������裬ֻ�������ڵĲ�ʹȫ�����������˳�ȥ!\n" NOR, me);
	}

        me->apply_condition("medicine", 5);
	
	destruct(this_object());
	return 1;
}
