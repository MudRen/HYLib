// Room: /u/jpei/thd/road1.c

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
һ���������·��Զ���ƺ��������䡣
LONG
	);
	set("no_clean_up", 0);
	set("outdoors","nio");

	set("exits", ([
		"north": __DIR__"road.c",
		"southeast": __DIR__"road2.c",
	]) );

	setup();
	replace_program(ROOM);
}

