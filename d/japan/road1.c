// Room: /d/japan/road1.c

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
һ�������Ĵ��,ʱ��ʱ�������,���ε�,С��,���˾���.�������
���˴����·���ʮ������,����ǰ��û����.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "japan");
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"nanmen",
  "southwest" : __DIR__"road2",
]));

	setup();
	replace_program(ROOM);
}
