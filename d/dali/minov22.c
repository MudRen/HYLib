//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "ũ��");
	set("long", @LONG
һƬ�ٺ��ĵ�����������ˮ���﹡�ܸߣ��Ҹ�����Թ���
��������ھ����൱�����ˮ��������گ��ˮ���㣬�Ӻ��ڶ࣬��Ȼ
��ɽ�ص��������Ҳ�������⡣��ȥ������Щ������ӡ�
LONG
        );

	set("exits", ([
		"southwest" : __DIR__"minov21",
		"east" : __DIR__"minov23",
		]));

	set("objects", ([
		__DIR__"npc/bynong.c" : 2,
		]));

	set("outdoors","dali");
	set("cost", 3);
	setup();
}
