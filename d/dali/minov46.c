//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "��Ϫ��");
	set("long", @LONG
��Ϫ��Ҳ���������������Ĳ��䡣���ﴦ���µأ������в���ũ
���ũҵ�����Ҫ�����ָ���������񾭳�Ǩ�㣬��������˼�
������⣬�������ݶ��ܼ�ª��
LONG
        );

	set("exits", ([
		"northwest" : __DIR__"minov45",
		"east" : __DIR__"minov54",
		"south" : __DIR__"minov55",
		]));

	set("objects", ([
		__DIR__"npc/wygirl.c" : 1,
		]));

	set("outdoors","dali");
	set("cost", 3);
	setup();
}
