// caroad4.c
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
		"northwest" : __DIR__"caroad3",
		"southeast" : __DIR__"caroad5",
	]));

	setup();
	replace_program(ROOM);
}
