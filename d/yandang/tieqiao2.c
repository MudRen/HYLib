// Room: /d/yandang/tieqiao2.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һ��������ߵ�������,��ʮ�����������,�������һ���
ľ��,���ڷ紵��ɹ,�����Զ,�еĵط��Ѿ���ȱ,���¾����������,
��˵�����˵���ȥ.���Ѿ����˽���һ����.���зǳ�����.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"tieqiao3",
  "south" : __DIR__"tieqiao1",
]));
	set("outdoors", "/d/yandang");

	setup();
	replace_program(ROOM);
}
