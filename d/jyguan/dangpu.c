// Room: /jyguan/dangpu.c
// YZC 1995/12/04 Shark Edit 10/08/1998

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ�Ҳ��ص��ĵ��̣������ɸ�����Ʒһ����߸ߵĹ�̨���������ǰ����̨
�ϰ���һ������(paizi)����̨�����ŵ����ϰ壬һ˫�������۾��������´������㡣
LONG
	);
	set("no_fight", 1);
	set("no_beg",1);

	set("item_desc", ([
		"paizi" : "���߲���\n",
	]));
	set("objects", ([
		__DIR__"npc/tang" : 1,
	]));
	set("exits", ([
		"west" : __DIR__"townroad1",
	]));

	setup();
	replace_program(ROOM);
}

