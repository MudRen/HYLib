// Room: /u/qingyun/jyzj/banshanya.c
// Written by qingyun
// Updated by jpei

inherit ROOM;

void create()
{
	set("short", "��ɽ����");
	set("long", @LONG
���������У���ߵ�ɽ��ʮ�����գ�ֱ���˰��ʱ��Ҳ���κ�ȥ·�ˡ�
LONG	);
	set("no_clean_up", 0);
/*	set("exits",([
	]));*/
	set("outdoors", "kunlun");
	setup();
}

void init()
{
	add_action("do_climb", ({"climb", "pa"}));
}

int do_climb(string arg)
{
	object me = this_player();

	if (arg == "east") {
		message_vision("$N�����������ȥ��\n", me);
		me->move(__DIR__"songshu");
		message("vision", me->name() + "�Ӱ�ɽ�������˹�����С�������������������\n", environment(me), ({me}));
		return 1;
	}
	return 0;
}