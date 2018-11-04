// Room: /d/yandang/shanlu4.c

inherit ROOM;

void create()
{
	set("short", "����̶");
	set("long", @LONG
����Ϫ�е�����̶�Ϳ�Խ���ϵĹ����ż�������,�ϳ�'��������'
����̶,λ�ڹ�������ɴ���֮��,��ԼĶ��,��10����.̶ˮ����,�峺
����,����һ����̵����.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"shanlu3",
  "north" : __DIR__"shanlu5",
]));
	set("outdoors", "/d/yandang");
	set("objects", ([ /* sizeof() == 3 */
  __DIR__"obj/biaoche.c" : 1,
  __DIR__"npc/footman.c" : 1,
  __DIR__"npc/biaotou.c" : 1,
]));

	setup();
	replace_program(ROOM);
}
