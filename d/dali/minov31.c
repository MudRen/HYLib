//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "���۲�");
	set("long", @LONG
����������·���ǰ��ĵ�һ֧--Щôͽ���۾ӵĵط����˵ؽ�ƫ
Զ������Ҳ��������һƬ����������ƺ�������ɽ��ˮ�㣬ɣ����
��������һƬСƽԭ����Щũ��˼�ɣ���࣬��˿������񸾶�
�÷�˿֯�顣
LONG
        );

	set("exits", ([
		"west" : __DIR__"minov28",
		"east" : __DIR__"minov32",
		"north" : __DIR__"minov33",
		"south" : __DIR__"minov36",
		]));

	set("objects", ([
		__DIR__"npc/byshang" : 1,
		]));

	set("outdoors","dali");
	set("cost", 2);
	setup();
}
