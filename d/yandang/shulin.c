// Room: /d/yandang/shulin.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
·�ߵ�һƬ������,����������������ľ,���ܵذ�������������,��
��Ũ�ܵ��Ӳ�������,������Σ��.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"to_yandang2",
  "north" : __DIR__"river",
]));
	set("outdoors", "/d/yandang");

	setup();
	replace_program(ROOM);
}
