// Room: /d/japan/road.c

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
  "west" : __DIR__"haigang",
  "northeast" : __DIR__"road2",
]));

	setup();
	replace_program(ROOM);
}
