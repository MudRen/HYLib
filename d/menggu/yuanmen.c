// Room: /d/menggu/yuanmen.c

inherit ROOM;

void create()
{
	set("short", "ԯ��");
	set("long", @LONG
ԯ�Űѱ�Ӫ�;�������ָ�����.ԭľ��ԯ�ű�����������ͨ�е�ÿ
һ����.�������ӭ����չ,һ��ֱ����ͨ����ľ���Ӫ��.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "menggu");
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"buluo1",
  "north" : __DIR__"road1",
]));

	setup();
	replace_program(ROOM);
}
