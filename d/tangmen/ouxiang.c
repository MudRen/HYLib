// Room: /d/tangmen/ouxiang.c
// BY hem

inherit ROOM;

void create()
{
	set("short", "ź��С�");
	set("long", @LONG
	����ź�����һ�����µ�С鿣�������е�С�������Ϲ��а���˿������
����һ��̨��̨���н�β���٣���ͭС����������̴�㡣һĨ�㲵���Ӱ��������ָ
��Ū�����ҡ�ԭ����ղ��������������������Ǵ���������ġ�
LONG
	);
	

	set("exits", ([
		
		"west" : __DIR__"qulang3",
		"east" : __DIR__"qulang4",
		"northeast" : __DIR__"qulang2",
		"southeast" : __DIR__"qulang5",
		
	]));
	set("objects", ([
		__DIR__"npc/tang_fang" : 1,
                __DIR__"npc/yahuan" : 1,
	]));


	setup();
	replace_program(ROOM);
}

