//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "³����");
	set("long", @LONG
���������Ჿ��³�������Ჿ��̨�ģ��������и�����Խ�ݡ�
����һ������ɽ���ϵ�С�򣬶���ͱ����Ǹ��ʵ�Ⱥɽ������������
�����ɼ���ׯ�ͳ���
LONG
        );

	set("exits", ([
		"north" : __DIR__"minov80",
		"south" : __DIR__"minov79",
		"west" : __DIR__"minov64",
		"east" : __DIR__"minov78",
		]));

	set("objects", ([
		__DIR__"npc/tyshang" : 1,
	]));

	set("outdoors","dali");
	set("cost", 2);
	setup();
}
