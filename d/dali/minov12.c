//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "����ذ�");
	set("long", @LONG
�����Ի�أ�ʵ�����Ǹ��ܴ�ĺ�������ɽ��ˮԴ�ڶ࣬Ҳ����
�˴�Ƭ��ũ���ˮ�峺��ˬ�������٤���ĸ�Ů�ڴ�ϴ����ˮ����
�Ĳ�������ҵΪ��������������Ȼ����С��ͷ��ʱ�����δ�ͣ����Ҳ
������������ˮ���㡣������������������С·���ŵ���ϰ���ȥ��
LONG
        );

	set("exits", ([
		"northeast" : __DIR__"minov11",
		"west" : __DIR__"minov19",
		]));

	set("objects", ([
		__DIR__"npc/bywoman.c" : 2,
		]));

	set("outdoors","dali");
	set("cost", 3);
	setup();
}
