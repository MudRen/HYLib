// Room: /d/hainan/road3.c

inherit ROOM;

void create()
{
	set("short", "С·");
	set("long", @LONG
����ʯ�̳ɵ�һ��С��,·�ľ�ͷ�Ǹ�СС������,����ľ�������� 
�д���.ʹ��ط�����һƬ�������.·���и�������������ɨ��. 
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"road2",
  "north" : __DIR__"baiyunan",
]));
	set("outdoors", "/d/hainan");
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/man1":1,
		__DIR__"npc/man2":1,

  __DIR__"npc/laonigu.c" : 1,
]));

	setup();
	replace_program(ROOM);
}
