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
	set_name("�����ⶾ��", ({"ndan1", "dan1"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�Ż����ⶾ�衣\n");
		set("value", 8000);
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
		message_vision(HIR "$N����һ�Ż����ⶾ�裬ֻ����ͷ�ؽ��ᣬҡҡ������ԭ������������ҩЧ�ʵ��䷴��\n" NOR, me);
	}
            else if ( (int)me->query_condition("medicine") > 0 )
	{
		me->add("max_neili", -5);
		message_vision(HIR "$N����һ�Ż����ⶾ�裬ֻ����ͷ�ؽ��ᣬҡҡ������ԭ����ʳ̫��̫�࣬ҩЧ�ʵ��䷴��\n" NOR, me);
	}
	else
	{
	me->apply_condition("snake_poison", 0);
        me->apply_condition("scorpion_poison", 0);
        me->apply_condition("xx_poison", 0);
        me->set("neili", 200);
        message_vision(HIG "$N����һ�Ż����ⶾ�裬ֻ�������ڵĶ���ȫ�����������˳�ȥ!\n" NOR, me);
	}

        me->apply_condition("medicine", 40);
	
	destruct(this_object());
	return 1;
}