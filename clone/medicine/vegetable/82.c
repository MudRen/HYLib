// ҩ��

inherit ITEM;
#include <ansi.h>
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

void init()
{
	add_action("do_eat", "eat");
	add_action("do_eat", "fu");
}

void create()
{
	set_name(order[random(13)]+"����"NOR, ({"zhong yao"}));
	set_weight(800);
	set("vegetable", 16);
	set("value", 30+random(121));
	set("nostrum", 32);
	set("unit", "��");
	set("long", "����һ��ҩ�ġ�\n");
	set("pour_type", "1");set("yaocao",1);
	setup();
}

int do_eat(string arg)
{
	object me = this_player();

	if(!id(arg)) return notify_fail("��Ҫ��ʲô��\n");
	if(!present(this_object(), me))
		return notify_fail("��Ҫ��ʲô��\n");
	if( me->is_busy() )
		return notify_fail("�𼱣������ԣ�С�ı�ҭ���ˡ�\n");
	me->add("food",20);
	me->add("water",20);
	write("���������ڰ�"+this_object()->query("name")+"������ȥ��\n");
	destruct(this_object());
	return 1;
}
