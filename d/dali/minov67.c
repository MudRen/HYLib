//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "�䶨��");
	set("long", @LONG
������̨�ķ�֧¬¹�����������θ����������������䶨���⻹
ϽԪı��»�����򡣴��򲻴�����ɽ����������Եø������ġ�
¬¹���˵���¥��ɢ�ֲ��������С�
LONG
        );

	set("exits", ([
		"northeast" : __DIR__"minov66",
		"north" : __DIR__"minov68",
		"south" : __DIR__"minov70",
		"west" : __DIR__"minov77",
		]));

	set("objects", ([
		__DIR__"npc/tygirl" : 1,
	]));

	set("outdoors","dali");
	set("cost", 2);
	setup();
}
