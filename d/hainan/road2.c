// Room: /d/hainan/road2.c

inherit ROOM;

void create()
{
	set("short", "С·");
	set("long", @LONG
����ʯ�̳ɵ�һ��С��,���ߵĻ��ݶ������ʮ�ֱ���.Զ��ɽ����
����Ŀ,������������¡����ˮ��.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/hainan");
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"road1",
  "northwest" : __DIR__"road3",
  "eastup" : __DIR__"road4",
]));

	setup();
	replace_program(ROOM);
}
