inherit ROOM;

void create()
{
        set("short", "�Ķ�����");
        set("long", @LONG
���������Ķ����֣����Ľֵ������˲�������һ������
���Ķ�����һ����¥������ֲ�Զ�����滮ȭ�Ⱦ�����������
���������ڶ���Ҳ������ȥʹ��һ������������С� 
LONG);
	set("outdoors", "zhongzhou");

        set("exits", ([
                "east" : __DIR__"yinghao",
                "south" : __DIR__"shizhongxin",
                "west" : __DIR__"xiaoxiang",
                "north" : __DIR__"wendingbei2",
        ]));

        set("objects", ([
	        __DIR__"npc/xianren" : 1,
        	__DIR__"npc/kid1": 1,
        ]));

        set("coor/x", -230);
	set("coor/y", 0);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
