// Room: /d/sandboy/zhulin1.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
һƬ�������֣����������̵������뵷�ɢ�������������������
������Ũ�ܵ���Ҷ����ӡ������Ա̡�
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/jiangnan");
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"zhulin",
  "west" : __DIR__"zhulin2",
  "south" : __DIR__"zhulin3",
]));

	setup();
	replace_program(ROOM);
}
