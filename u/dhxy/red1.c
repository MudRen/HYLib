// lingzhi.c ǧ��ѩ��
//����(lywin)2000/4/22

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
        set_name(HIR"С����"NOR, ({"hxsd"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
    set("no_give","ÿ����ֻ��һ�����㶼��ô�󷽣�\n");
    set("value", 0);
set("liwu",1);
set("no_steal",1);
set("no_beg",1);
    set("no_put",1);
    set("no_get","ÿ����ֻ��һ������Ҫ��ô̰�ģ�\n");
    set("no_drop","��ô���Ķ�����Ҳ�ӣ���\n");

		set("unit", "��");
                set("long", "����һ��СС��С������������л����������˵��һ���ܲ����塣\n");
		set("value", 0);
	}
	setup();
}

int do_eat(string arg)
{
	if (!id(arg))
	return notify_fail("��Ҫ��ʲô��\n");
        this_player()->start_busy(30);
        this_player()->add("max_neili", 20);
        this_player()->add("eff_neili",20);
        message_vision("$N����һ��С�������һ�������������ų����о����Լ���������ǿ�˲��� !\n", this_player());

	destruct(this_object());
	return 1;
}

void owner_is_killed()
{
	destruct(this_object());
}