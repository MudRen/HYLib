//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "�ӱ�");
	set("long", @LONG
�������ӱߣ�����ɽ�ڼ�����ֱ��ֱ�£�������һ������Ա���
���������ڴ����򶫱��ڶ�ȥ����ˮ��ӿ���������죬����һ����
�˵ĺ��졣�˴��ӹ���խ��ǰ������������������һ�ô����ϣ���һ
�˿�Ӷ������ƿ���Ԯ��������ȥ�������ǳ�ɽ���롣
LONG
        );

	set("exits", ([
		"east" : __DIR__"minov92",
		"south" : __DIR__"minov52",
		]));

	set("objects", ([
		__DIR__"npc/wyshang.c" : 1,
		]));

	set("outdoors","dali");
	set("cost", 3);
	setup();
}
