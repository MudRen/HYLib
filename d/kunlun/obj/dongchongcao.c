// dongchongcao.c �����

#include <ansi.h>
inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_fu", "fu");
}

void create()
{
	set_name(HIB"�����"NOR, ({"dongchong cao", "cao"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", HIB"����һ���ļ��Ӷ����������е��������ϳ����Ķ����Ĳݡ�\n"NOR);
set("value", 2500);
	}
	setup();
}

int do_fu(string arg)
{
	string what = query("cure");
	int howmuch = query("amount");

	if (!id(arg))
		return notify_fail("�����ʲô��\n");

	if ((int)this_player()->query("eff_qi") ==
		 (int)this_player()->query("max_qi"))
		return notify_fail("����������û���ܵ��κ��˺���\n");
	else {
		this_player()->receive_curing("qi", 50);
		message_vision("$N��һ�궬��ݷŽ����н��飬С�ķ����˿��ϣ���ɫ�������ö��ˡ�\n", this_player());
		destruct(this_object());
		return 1;
	}
}

