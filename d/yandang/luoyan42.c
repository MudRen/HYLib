// Room: /d/yandang/luoyan42.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
��������ׯ�е����书���г���ʱ�����д�ĵط�,�������ӵĵ�
��Ҳ��Ը�һЩ.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"luoyan40",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/peilian2.c" : 3,
]));

	setup();
	replace_program(ROOM);
}
