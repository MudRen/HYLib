//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "����ɽ����");
	set("long", @LONG
�����Ǹ���ɽ�Ķ��£��򶫸��ӱ��ʶ����Ķ���ˮ��ԶԶ������
����Եı���ѩɽ����ȥ������ȫ�ǳ�ɽ���룬����ϡ�١�ɽ������
�޶࣬����������˾�����ɽ���ԡ�
LONG
        );

	set("exits", ([
		"eastdown" : __DIR__"minov45",
		"west" : __DIR__"minov56",
		]));

	set("objects", ([
		__DIR__"npc/goat.c" : 1
		]));

	set("outdoors","dali");
	set("cost", 3);
	setup();
}
