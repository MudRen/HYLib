// Room: /d/tangmen/guajiantang.c
// xws 1998/11/05

inherit ROOM;

void create()
{
	set("short", "�ҽ���");
	set("long", @LONG
	�����ǹҽ��á��������������ң���Ȼ�кܶ�ϲ���ռ��������ˡ����Ǳ���
֮���������������ռ����Ѿ��в���������������ڹҽ����С�
LONG
	);
	

	set("exits", ([
		"north" : __DIR__"changlang11",
		"west" : __DIR__"duanmuting",
		"east" : __DIR__"changlang17",
		"up" : __DIR__"jiaolou6",
	]));
       set("objects", ([
		__DIR__"npc/dizi" : 4,
			]));

	setup();
	replace_program(ROOM);
}

