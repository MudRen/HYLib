// zhujia.c ���׷�
// ����lywin 2000/9/2 

#include <ansi.h>
inherit ROOM;

 void create()
{
        set("short", "����");
        set("long", @LONG
����һ����ƽ����ͨ�����У���������������,�������ʲô
���ƵĶ���������������sell���ȥ,��value���ۡ�
LONG
        );

        set("exits", ([
                "north" : "d/xiangyang/dangpu",
        ]));
	set("objects", ([
		__DIR__"shangren" : 1,
	])); 

        set("no_fight",1);
        set("no_beg",1);
        set("no_steal",1);
        setup();
}

