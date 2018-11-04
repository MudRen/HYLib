// Room: /u/qingyun/jyzj/cuigu.c
// Written by qingyun
// Updated by jpei

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"���츣��"NOR);
	set("long", @LONG
���ö�����ͻȻ������ҫ�ۣ�������۶�һ������������������ǰ����
�����Ž��صĴ�ȣ��컨������������ӳ��ɽ����ؾ�Ȼ��������������һ
Ծ�������ŵأ��Ų���̤�ŵ�������ϸ�ݣ������ŵ��������Ļ��㣬��������
�������ݼ�أ���ǰ���ֵ����ʹ���֦������ôҲ�����뵽����������Ķ�Ѩ
֮�󣬾���������һ�����츣�ء�
LONG	);
	set("exits",([
		"north" :   __DIR__"cuigu1",
		"eastup" : __DIR__"shanbi",
		"west" :  __DIR__"pubu",
	]));
	set("objects", ([
		__DIR__"obj/rock" : 1,
	]) );
	set("outdoors", "kunlun");
	set("no_clean_up", 0);

	setup();
}

void init()
{
	add_action("do_zuan", "zuan");
}

int do_zuan(string arg)
{
	object me = this_player();

	if (arg == "dong") {
		message("vision", me->name() + "һ�����������ɽ����\n", environment(me), ({me}));
		write("�㼱��ææ������˶��ͷײ����ɽʯ��ֱʹ������۴�С�\n");
		me->move(__DIR__"shandong");
		message("vision", me->name() + "���˽�����ͷ��ײ����ɽʯ�ϡ�\n", environment(me), ({me}));
		return 1;
	}
	return 0;
}
