//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����һ�ô��������������ڴ˽���һ���൱��ĸ������²�����
��һ��Ȧ��ʮ��ͷţ���Աߵ�¥���޵��Ŀ����������Ǳ��ص���
���˼ҡ�
LONG
        );

	set("exits", ([
		"west" : __DIR__"minov22",
		"up" : __DIR__"minov24",
		]));

	set("objects", ([
		__DIR__"npc/goat.c" : 3,
		__DIR__"npc/niu.c" : 2,
		]));

	set("outdoors","dali");
	set("cost", 2);
	setup();
}
