// Room: /u/qingyun/jyzj/xiepo2.c
// Written by qingyun
// Updated by jpei

inherit ROOM;

void create()
{
      set("short", "ѩɽб��");
	set("long", @LONG
���ֽ��ŵأ�����ѩɽб�£�һ��һ������������֮����ȥ�������ͱڱ�
�ͼ��������϶����ѩ�����ǻ����ޱȣ�һ��С�ľͻỬ����
LONG);
	set("exits",([
		"east" :  __DIR__"dashibi",
	]));
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

	if (arg == "west") {
		message_vision("$N��������ȥ��\n", me);
		me->move(__DIR__"xiepo1");
		message("vision",me->name() + "���˹�����\n", environment(me), me);
		return 1;
	}
	return 0;
}

