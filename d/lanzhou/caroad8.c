// caroad8.c
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
		"north" : __DIR__"caroad7",
		"east" : "/d/city4/westgate",
	]));

	setup();
	replace_program(ROOM);
}
