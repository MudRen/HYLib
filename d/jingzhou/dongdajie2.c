// Room: /jingzhou/dongdajie2.c
// congw 98/08/30

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
�����ڶ�����ϣ����ż�ʵ����ʯ����档�����Ƕ����ţ�����������
�ǹٱ���ߺ���������������ʵĶ�����������һ�𡣱�����һ��СС���ӻ��̣�
LONG
	);
        set("outdoors", "city");

	set("exits", ([
		"east" : __DIR__"jzdongmen",
		"west" : __DIR__"dongdajie1",
		"north" : __DIR__"shop",
		"south" : __DIR__"xxiang",
	]));

	setup();
	replace_program(ROOM);
}

