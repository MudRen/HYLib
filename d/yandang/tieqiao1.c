// Room: /d/yandang/tieqiao1.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һ��������ߵ�������,��ʮ�����������,�������һ���
ľ��,���ڷ紵��ɹ,�����Զ,�еĵط��Ѿ���ȱ,���¾����������,
��˵�����˵���ȥ.���Ѿ�����һС����.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/yandang");
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"tieqiao2",
  "south" : __DIR__"dongyaotai",
]));
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/youke.c" : 1,
  __DIR__"npc/lanyi.c" : 1,
]));

	setup();
	replace_program(ROOM);
}
