// Room: /u/jpei/thd/njroad2.c

inherit ROOM;

void create()
{
	set("short", "����С·");
	set("long", @LONG
һ�����е�С·��·����һ���񷿣�����ܾ�û����ס�������ˡ�
LONG
	);
	set("no_clean_up", 0);
	set("outdoors","nio");

	set("exits", ([
		"west": __DIR__"njroad1.c",
		"east": __DIR__"njroad3.c",
		"north": __DIR__"guojia.c",
	]) );
	set("objects", ([
	"/d/xiangyang/npc/girl" : 1,
	]) );

	setup();
	replace_program(ROOM);
}

