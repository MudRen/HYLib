inherit ROOM;

void create()
{
        set("short", "�Ķ��Ͻ�");
        set("long", @LONG
���������Ķ��Ͻ֣����Ľֵ������˲�������һ������
���Ķ���������������һ���˳��������һ�ҵ��棬һ������
����������֪����һ�Ҳ�С��Ǯׯ��
LONG);
	set("outdoors", "zhongzhou");

        set("exits", ([
                "east" : __DIR__"canchang",
                "south" : __DIR__"wendingnan2",
                "west" : __DIR__"bank",
                "north" : __DIR__"shizhongxin",
        ]));
        set("objects", ([
                "/d/city/npc/liumang" : 1,
        ]));

        set("coor/x", -230);
	set("coor/y", -20);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}

