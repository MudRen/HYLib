// Room: /d/sandboy/zhulin3.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
һƬ���������µ����֣��Ų�������Ҷ�Ϸ���ɳɳ������������һ����
���������л�����������������ޱȡ�
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/jiangnan");
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"zhulin1",
  "west" : __DIR__"zhulin5",
]));

	setup();
	replace_program(ROOM);
}
