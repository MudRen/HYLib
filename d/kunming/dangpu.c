// Room: /city/dangpu.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
����һ�Һ���Щ��ʷ���ϵ����ˣ��߸ߵĹ�̨�������ŵ��̵���
�壬����һ����ֵ��۹⿴���㣬һ�������������žž�Ĵ�������
���������ˣ�Ҳ���к�һ�¡���̨�Ķ��Ϲ���һ������(paizi)��
LONG
	);
	set("no_fight", 1);
	set("no_beg",1);

	set("item_desc", ([
		"paizi" : "��ƽ����\n",
	]));
	set("objects", ([
		__DIR__"npc/liu" : 1,
	]));
	set("exits", ([
		"east" : __DIR__"nandajie1",
	]));

	setup();
	replace_program(ROOM);
}

