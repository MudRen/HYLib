// caroad3.c
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
		"north" : __DIR__"caroad2",
		"southeast" : __DIR__"caroad4",
	]));

	setup();
	replace_program(ROOM);
}
