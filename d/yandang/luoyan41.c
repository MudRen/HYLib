// Room: /d/yandang/luoyan41.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
��������ׯ�е��ӳ����书�ĵط�,�˴������������书�ǱȽϵ�
��,�����ڳ�ѧ�߾͹���.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"luoyan40",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/peilian1.c" : 3,
]));

	setup();
	replace_program(ROOM);
}
