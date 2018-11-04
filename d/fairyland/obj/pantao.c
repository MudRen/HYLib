// pantao.c ���
// By jpei

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name("���", ({"peach", "pantao", "pan tao", "tao"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "ö");
		set("long", "����һöȭͷ��С����ҡ�\n");
		set("value", 300);
	}
	setup();
}

void init()
{
	add_action("do_eat", ({"eat", "chi"}));
}

int do_eat(string arg)
{
	object me = this_player();

	if (!id(arg)) return notify_fail("��Ҫ��ʲô��\n");

	if (me->query_condition("bonze_drug")) {
		message_vision("$N����һö��ң��ƺ�����ô�����ˡ�\n", me);
		if (me->query("food") < me->max_food_capacity())
			me->add("food", 30);
	}
	else
	{
		me->add("max_neili", 1);
		message_vision(HIG "$N����һö��ң����ڵ������ƺ���Щ�Ķ���\n" NOR, me);
		me->apply_condition("bonze_drug", 200);
	}
	destruct(this_object());
	return 1;
}
