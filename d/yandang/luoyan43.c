// Room: /d/yandang/luoyan43.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
��������ׯ�е����书�г�������ĵط�,����������ﻹ�ǲ���
����Ļ�,�������ɽ��.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"luoyan40",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/peilian3.c" : 3,
]));

	setup();
	replace_program(ROOM);
}
