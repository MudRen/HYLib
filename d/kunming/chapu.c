// Room: /city/chaguan.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���ŷ������������ʣ���ݵ���ʩ��Ȼ��ª��ȴ��һ�����ȥ�������
��������̸��˵�أ����������������������������£����Գ�������
��û�¶�����������һ�������ϼ���ˮ�̣����ϵر������ġ�
LONG
	);
	set("resource/water", 1);

	set("exits", ([
		"west" : __DIR__"nandajie2",
	]));

	set("objects", ([
		__DIR__"npc/chaxiaoer" : 1,
		__DIR__"npc/obj/yantong":1,
	]));

	setup();
	replace_program(ROOM);
}

