//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "�����в�");
	set("long", @LONG
�����Ǹ������в㣬��¥��һ�������Ǽ�������گ���Ĵ���ŷ�
�Լ��������е��������Ҽһ������������谸����в�����෿��
��Ϊ���������ݿ�������һ����ɴ����
LONG
        );

	set("exits", ([
		"down" : __DIR__"minov34",
		]));

	set("objects", ([
		__DIR__"npc/byfangsha.c" : 1,
		]));

	set("cost", 2);
	setup();
}
