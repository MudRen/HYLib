//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
������һƬï�ܵ�ɽ���У�ʱ���з������޺�����������ּ��
�����ϱ����Ĳ�����Ĵ��񾭳��������ԡ�ɽ�ֱ��治Զ����¡¡ˮ
���������д���������ϱ���һƬ���ݵĺӹ���أ��������̡�
LONG
        );

	set("exits", ([
		"north" : __DIR__"minov93",
		"southdown" : __DIR__"minov47",
		]));

	set("objects", ([
		__DIR__"npc/wylieren.c" : 1,
		]));

	set("outdoors","dali");
	set("cost", 3);
	setup();
}
