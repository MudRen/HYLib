// caroad2.c
// by xws

inherit ROOM;

void create()
{
	set("short", "��ʯ���");
	set("long", @LONG
������һ����ʯ����ϣ����������ǳ���æ����ʱ������������ҴҶ�����
ԶԶ�ı��߾��ܿ��������ˣ��ϱ�ͨ��������
LONG
	);
        set("outdoors", "lanzhou");

	set("exits", ([
		"north" : __DIR__"caroad1",
		"south" : __DIR__"caroad3",
	]));

	setup();
	replace_program(ROOM);
}
