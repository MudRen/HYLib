// caroad5.c
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
		"northwest" : __DIR__"caroad4",
		"east" : __DIR__"caroad6",
	]));

	setup();
	replace_program(ROOM);
}
