//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "�������ϰ�");
	set("long", @LONG
���������Բ����洬��ͷ��������̨�Ĵ������������񷤣�һЩ
���������º����㣬���ʵ��������ڸ�����ϲ�ݡ����ڵȳ���
�����ü�Ǯ��
LONG
        );

	set("exits", ([
		"south" : __DIR__"minov72",
		]));

	set("objects", ([
		__DIR__"npc/tyfisher" : 1,
	]));

	set("outdoors","dali");
	set("cost", 3);
	setup();
}
