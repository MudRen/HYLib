// Room: /u/jpei/thd/road2.c

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
һ���������·�����Ϸ�����һ��СС�Ĵ��䡣
LONG
	);
	set("no_clean_up", 0);
	set("outdoors","nio");

	set("exits", ([
		"northwest": __DIR__"road1.c",
		"southeast": __DIR__"njwest.c",
	]) );

	setup();
	replace_program(ROOM);
}

