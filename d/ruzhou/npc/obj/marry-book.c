// Obj: /d/ruzhou/npc/obj/marry-book.c �����֪
#include <ansi.h>

inherit ITEM;

void init()
{
        add_action("do_read", "fan");
}

void create()
{
	set_name("�������֪��", ({ "jiehun xuzhi", "xuzhi"}));
	set("weight", 600);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 500);
		set("material", "paper");
		set("long", "�Ȿ����д�ű�MUD���ĳ�������Է���(fan)����\n");
	}
	setup();
}

int do_read(string arg)
{
    if (!arg||(arg!="jiehun xuzhi"&&arg!="xuzhi"))
        return notify_fail("��û���Ȿ�飬�ҷ��ڴ���ʲô��\n");
    this_player()->start_more(read_file("/doc/help/marry"));
    return 1;
}

