// Room: /d/yandang/luoyan35.c

inherit ROOM;

void create()
{
	set("short", "��԰");
	set("long", @LONG
�߽��¶���,����һ��С��԰,�����˸��ֻ���,��,��,��,��,��һ��
��,�м�������ʯ�̳ɵ�С·�ڲ�ľ������,������һ�����Ĵ���,
���ǿ��˾���.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"luoyan34",
  "north" : __DIR__"luoyan36",
]));
	set("outdoors", "/d/yandang");

	setup();
	replace_program(ROOM);
}
