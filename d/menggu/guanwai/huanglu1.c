// Room: /d/menggu/huanglu1.c

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
���������ӹ�����Ļ�·������Զ���������ϡ�١�
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "menggu");
	set("exits", ([ /* sizeof() == 2 */
  "southdown" : "/d/guanwai/road8",
  "northwest" : __DIR__"damo2",
]));

	setup();
	replace_program(ROOM);
}
