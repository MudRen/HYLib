// xtj 
// by dubei

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
    set("short", BLU "С��"NOR);
    set("long", @LONG
�������ٲ������һ��С������ϥ��Ұ�ݼ�����·���ڸ��ˡ�
LONG
    );

    set("outdoors", "xiangyang");

    set("exits", ([
        "east" : __DIR__"pubu",
        "northwest" : __DIR__"dongkou",
    ]));

    setup();
    replace_program(ROOM);
}
