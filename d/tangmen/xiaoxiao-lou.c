// Room: /d/tangmen/xiaoxiao-lou.c
// xws 1998/11/05

inherit ROOM;

void create()
{
	set("short", "����ĺ��¥");
	set("long", @LONG
	����ĺ��¥��Ȼ����¥������ȴֻ��һ�㡣������������������ɫ�Ľ���
¥��������״�����������������ϣ�������ʮ���ɸߣ�������ߴ����������Կ���Զ
���������ʵĳ������档���ǡ�����ĺ�������족��������
LONG
	);
	

	set("exits", ([
		"north" : __DIR__"changlang20",
		"west" : __DIR__"bingqiku",
		"eastup" : __DIR__"jiaolou4",
		"south" : __DIR__"changlang12",
	]));

	setup();
	replace_program(ROOM);
}

