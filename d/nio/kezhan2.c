// Room: /u/jpei/thd/kezhan2.c

#include <room.h>
inherit ROOM;

int do_unlock();
string look_men();

void create()
{
	set("short", "��¥");
	set("long", @LONG
���ǿ�ջ�Ķ�¥����Ȼֻ�����䷿�ӡ����᷿���ų����ţ������᷿����
(men)ȴ�ǹ��ŵġ�
LONG
	);
	set("no_clean_up", 0);

	set("item_desc", ([
		"men" : (: look_men :),
	]));

	set("exits", ([
		"east": __DIR__"kezhan3.c",
		"down": __DIR__"kezhan.c",
	]) );

	setup();
}

void init()
{
	add_action("do_unlock", "unlock");
	add_action("do_unlock", "kai");
}

int do_unlock()
{
	object ob;
	object me = this_player();

	if (me->is_busy() || me->is_fighting())	return notify_fail("����æ���أ�\n");
	if (__DIR__"kezhan4.c"->query_temp("busy")) 
		return notify_fail("�������Ѿ����˴����淴���ˡ�\n");
	if (!(ob = present("kezhan key", me)))
		return notify_fail("�㲻��������\n");
	message_vision("$N��һ��Կ�״������᷿�š�\n", me);
	destruct(ob);
	this_player()->move(__DIR__"kezhan4");
	return 1;
}

string look_men()
{
	if (__DIR__"kezhan4.c"->query_temp("busy")) 
		return "�������Ѿ����˴����淴���ˡ�\n";
	else
		return "�������Ϲ���һ�Ѵ�������\n";
}
