// /d/xiangyang/outsroad1.c

inherit ROOM;

void create()
{
	set("short", "��ʯ���");
	set("long", @LONG
������һ����ʯ����ϣ����������ǳ���æ����ʱ����������ҴҶ�����
������Ͻ�����Ͼ��ڡ�����ͨ�������ǡ�
LONG
	);
        set("outdoors", "xiangyang");

	set("exits", ([
		"south" : __DIR__"outsroad2",
		"north" : "d/xiangyang/caodi2",
	]));

	setup();
	replace_program(ROOM);
}

