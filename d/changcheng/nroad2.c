// Room: /d/wizhome/incahome/nroad2.c
// Date: inca 98/08/13

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
������һ����������Ĵ�����ϡ����ܵ��˲��Ǻܶࡣż����
�������򣬴Ҵ�������ȥ����ʱ����������������߷ɳ۶�����
����һ·��������·��������������������֡�������ԶԶ�ľ�
�������������ǡ�
LONG
	);

	set("exits", ([
		"south"  : __DIR__"nroad1",
		"north" : __DIR__"juyguan",
	]));

        set("outdoors", "changcheng");

	setup();
	replace_program(ROOM);
}



