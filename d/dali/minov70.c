//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "ũ��");
	set("long", @LONG
һСƬ��ɽ���µ������￪�ѳ�����ũ�����Ϫ������ֲ��ˮ
����̨������ܴ�̶�������ũҵ������ũҵ��ȴ�������Ǹ�Ů����
�Ӵ�ר˾���ԺͲ��㡣
LONG
        );

	set("exits", ([
		"north" : __DIR__"minov67",
		]));

	set("objects", ([
		__DIR__"npc/tynong" : 1,
	]));

	set("outdoors","dali");
	set("cost", 3);
	setup();
}
