// caroad1.c
// by xws

inherit ROOM;

void create()
{
	set("short", "��ʯ���");
	set("long", @LONG
������һ����ʯ����ϣ����������ǳ���æ����ʱ������������ҴҶ�����
���������һЩС��̯�����߾͵������ˣ��ϱ�ͨ��������
LONG
	);
        set("outdoors", "lanzhou");

	set("exits", ([
		"north" : __DIR__"nanmen",
		"south" : __DIR__"caroad2",
	]));

	setup();
	replace_program(ROOM);
}
