// Room: /jyguan/jiudian.c
// YZC 1995/12/04 , 1998/10/08 Shark Edit

inherit ROOM;

void create()
{
	set("short", "С�ƹ�");
	set("long", @LONG
	��Բ����������Ҿƹݺ��ǳ����������߽�ʿ����������Ѱ�ֽ��Ƶĳ�
����¥�²��ü��ף��˿Ͷ��ǴҴҵ����ˣ������ӡ����ȡ��׾ƾ͸�·ȥ�ˡ�
¥����������
LONG
	);

	set("exits", ([
		"west" : __DIR__"townroad",
		"up" : __DIR__"zuixianlou2",
	]));

	set("objects", ([
		__DIR__"npc/xiaoer2" : 1,
	]));

	setup();
	replace_program(ROOM);
}

