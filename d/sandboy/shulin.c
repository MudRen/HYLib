// Room: /d/sandboy/shulin.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
·�ߵ�һƬ������,����������������ľ,���ܵذ�������������,��
��Ũ�ܵ��Ӳ�������,������Σ��.
LONG
	);
set("outdoors","/d/jiangnan");
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"river",
  "south" : __DIR__"to_zhongzhou2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
