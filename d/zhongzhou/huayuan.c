inherit ROOM;

void create()
{
        set("short", "С��԰");
        set("long", @LONG
������̫ү��ǰ��С��԰��������ľ�����ﻨ�㡣��һ��
���еĵط���͸��һ��ĵ���������������̫ү�ĸ�ۡ������
���᷿��΢�¾�һ�㡣�����Ǹ������˵����ӡ�
LONG);
	set("outdoors", "zhongzhou");

        set("exits", ([
                "west" : __DIR__"xiaren",
                "north" : __DIR__"taiyefu",
                "east" :__DIR__"zoulang", 
        ]));

        set("coor/x", -260);
	set("coor/y", 20);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}

