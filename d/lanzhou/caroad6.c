// caroad6.c
// by xws

inherit ROOM;

void create()
{
	set("short", "��ʯ���");
	set("long", @LONG
������һ����ʯ����ϣ��˽�����������ֻ����ʱ����������ҴҶ�����

LONG
	);
        set("outdoors", "lanzhou");

	set("exits", ([
		"west" : __DIR__"caroad5",
		"south" : __DIR__"caroad7",
	]));

	setup();
	replace_program(ROOM);
}
