//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
���Բ�ר�����ԣ�����������������������һ����ͨ����¥��
�²�ͨ��������Ȧ���޲��������Ĺ��һλ̨�ĸ�Ů����ϸ�ĵ�
"��֯������¥����һ��ľ�ܣ����������ŵ��㣬������ɹ��ɡ�
LONG
        );

	set("exits", ([
		"east" : __DIR__"minov72",
		]));

	set("objects", ([
		__DIR__"npc/tywoman" : 1,
	]));

	set("outdoors","dali");
	set("cost", 2);
	setup();
}
