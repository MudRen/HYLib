//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "��¥");
	set("long", @LONG
һ���׼��̨����¥������ǽ�ڽ������ӣ���������һ��������
����̨�����ڼ�������¯�����崫ͳϯ�ض�˯�����������޴�����ǽ
���е��죬�����ڳ���ʯ�Ѽ�̨����޼Ҿߡ�
LONG
        );

	set("exits", ([
		"down" : __DIR__"minov68",
		]));

	set("objects", ([
		__DIR__"npc/tykid" : 1,
	]));

	set("cost", 2);
	setup();
}
