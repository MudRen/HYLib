// senlin.c
#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
       set("short","ԭʼɭ��");
       set("long", 
"���Ǿ���ͨ��������һ��ɭ�֣�ɭ���е��²�����һ�������Ҷ����ȥ
�������죬͸��ɭ�ֵ�һЩ���������£��������������ϱ��߿��Լ������ɵ���\n"
);
        set("exits", ([
                "northwest" : __DIR__"linzi",
//                "northeast" : "",
                "west" : __DIR__"path3",
                "southeast" : __DIR__"zhongxiandao",
        ]));
        
        set("objects", ([
                         __DIR__"npc/bird" : 1,
        ]));

        set("outdoors", "feitian");

        setup();
       replace_program(ROOM);
}