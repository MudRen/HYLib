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
		"west" : __DIR__"road8",
		"east" : __DIR__"road4",
	]));

 	set("outdoors", "zhuojun");
	setup();
	replace_program(ROOM);
}



