// /d/zhuojun/road6.c
// Room in �ÿ�
// modify by yang

inherit ROOM;


void create()
{
	set("short", "�潭ɽ·");
	set("long", @LONG
������һ����ʯ����ϣ������ǹ������潭,�˴���
Ⱥϡ�٣�����Ҳ�����ĵġ�
LONG );
	set("exits", ([
		"north" : "/d/nanchang/nanmen",
		"east" : __DIR__"road7",
	]));

 	set("outdoors", "zhuojun");
	setup();
	replace_program(ROOM);
}



