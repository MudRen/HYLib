// Room: /d/sandboy/zhulin4.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
һƬ���׵����֣����̵���Ҷӯӯ���Σ����Ϸ����������ӵ���������
��������Ƭ��������������С���֣������������
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/jiangnan");
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"zhulin2",
  "north" : __DIR__"zizhuan",
]));

	setup();
	replace_program(ROOM);
}
