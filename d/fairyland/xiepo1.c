// Room: /u/qingyun/jyzj/xiepo1.c
// Written by qingyun
// Updated by jpei

inherit ROOM;

void create()
{
	set("short", "ѩɽб��");
	set("long", @LONG
���ֽ��ŵأ�����ѩɽб�£�һ��һ������������֮����ȥ�������ͱڱ�
�ͼ��������϶����ѩ�����ǻ����ޱȣ�һ��С�ľͻỬ����
LONG	);
/*	set("exits",([
	]));*/
	set("outdoors", "kunlun");
	set("no_clean_up", 0);
	
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
		message("vision", me->name() + "����̫������ĵط���ȥ��\n", environment(me), ({me}));
		write("�������ѩɽб����ȥ��\n");
		me->move(__DIR__"xiepo2");
		message("vision", me->name() + "���˹�����\n", environment(me), ({me}));
		return 1;
	}
	if (arg == "west") {
		message_vision("$N�����ߵ�������ȥ��\n", me);
		me->move(__DIR__"songshu");
		message("vision", me->name() + "��ѩɽб�����˹�����С�������������������\n", environment(me), ({me}));
		return 1;
	}
	return 0;
}
