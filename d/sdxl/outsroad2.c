// /d/xiangyang/outsroad2.c

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
		"south" : __DIR__"outsroad3",
		"north" : __DIR__"outsroad1",
	]));

	setup();
	replace_program(ROOM);
}

