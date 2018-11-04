// Room: /u/jpei/thd/kezhan4.c

#include <room.h>
inherit ROOM;

int do_open(string arg);
int do_quit();
int do_goto();
int do_home();
int do_gg();

void create()
{
	set("short", "���᷿");
	set("long", @LONG
��һ�߽����᷿���Ͱ��ŷ����ˡ��������ܣ�ֻ��һ�Ŵ���һ�Ų��Ƶ���
��(zhuozi)��
LONG
	);
	set("no_clean_up", 0);

	set("item_desc", ([
		"zhuozi" : "һ�Ų��Ƶ�����������(chouti)¶��һ����϶�������Ϸ���һ�����Ƶ��ռ�(riji)��\n",
		"chouti" : "͸����϶���￴���ں�����ʲôҲ�����壡\n",
		"riji" : "�ռ�������ֵķ��Ż���������ͼ����\nThere are so many jewels...If I can remember the location, but I think the\nsailer will remember...\n",
	]));

	set("exits", ([
		"east": __DIR__"kezhan2.c",
	]) );

	setup();
}

void init()
{
	add_action("do_open", "open");
	add_action("do_quit", "quit");
	add_action("do_goto", "goto");
	add_action("do_gg", "gg");
	add_action("do_home", "home");
	set_temp("busy", 1);
}

void delete_got()
{
	delete_temp("jing_got");
}

int do_open(string arg)
{
	object me = this_player();

	if (me->is_busy() || me->is_fighting())	return notify_fail("����æ���أ�\n");
	if (arg == "chouti") {
		if (!query_temp("jing_got") && !present("wangyuan jing", me)) {
			write("������ش򿪳��룬������һ����ֵĶ�������������ԲͰ�����۾�����ȥ������Ȼ�ܿ���Զ����\n");
			set_temp("jing_got",1);
			new(__DIR__"obj/wangyuan")->move(me);
			remove_call_out("delete_got");
			call_out("delete_got", 300);
		}
		else 
			write("������ش��˳��룬ȴ���������ǿյġ�\n");
		return 1;
	}
	return notify_fail("��Ҫ��ʲô��\n");
}

int do_quit()
{
	write("���ﲻ׼�˳���\n");
	return 1;
}

int do_goto()
{
	if (wiz_level(this_player()) > 0)
		delete_temp("busy");
	return 0;
}

int do_home()
{
	if (wiz_level(this_player()) > 1)
		delete_temp("busy");
	return 0;
}

int do_gg()
{
	if (wiz_level(this_player()) > 2)
		delete_temp("busy");
	return 0;
}

int valid_leave(object me, string dir)
{
	delete_temp("busy");

	return ::valid_leave(me, dir);
}
