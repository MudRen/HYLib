// Room: /d/hainan/road1.c

inherit ROOM;

void create()
{
	set("short", "С·");
	set("long", @LONG
����ʯ�̳ɵ�һ��С��,�����Ǹ��ֻ���,������㶼û����.�ʵ���
���з���.����ʮ�ֵ�����!
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/hainan");
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"caodi",
  "north" : __DIR__"road2",
]));

	setup();
	replace_program(ROOM);
}
