// Room: /d/tangmen/meiyuan1.c
// xws 1998/11/05

inherit ROOM;

void create()
{
	set("short", "÷԰");
	set("long", @LONG
	���������е�һ��Ƭ÷�֣�ÿ����԰÷�����ţ�����Ϯ�ˣ����˾���������
ˬ����������һ��������
LONG
	);
	
set("outdoors", "tangmen");
	set("exits", ([
		
		"south" : __DIR__"xiouxishi",
		"east" : __DIR__"meiyuan2",
	]));

	setup();
	replace_program(ROOM);
}

