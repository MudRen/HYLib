// Room: /d/tangmen/zhanmeige.c
// xws 1998/11/05

inherit ROOM;

void create()
{
	set("short", "չ÷��");
	set("long", @LONG
	������չ÷�����ڸ�������һ��Ƭ÷Բ��ÿÿ÷�����������ţ�����
�����Ʈ�����У��������㣬������⡣
LONG
	);
	

	set("exits", ([
		"north" : __DIR__"changlang13",
		"west" : __DIR__"meiyuan2",
		"south" : __DIR__"changlang14",
	]));

	setup();
	replace_program(ROOM);
}

