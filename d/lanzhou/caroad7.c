// caroad7.c
// by xws

inherit ROOM;

void create()
{
	set("short", "��ʯ���");
	set("long", @LONG
������һ����ʯ����ϣ��˽�����������ֻ����ʱ����������ҴҶ�����
ԶԶ�����Ѿ����Կ����������ˡ�
LONG
	);
        set("outdoors", "lanzhou");

	set("exits", ([
		"north" : __DIR__"caroad6",
		"south" : __DIR__"caroad8",
	]));

	setup();
	replace_program(ROOM);
}
