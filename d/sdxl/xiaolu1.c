// xtj 
// by dubei

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
    set("short", BLU "С��"NOR);
    set("long", @LONG
����һ����Լ�ɱ��С·�������������֮��������춶���Խ������
����Խ�죬���Ǽ����ˮ����
LONG
    );

    set("outdoors", "xiangyang");

    set("exits", ([
        "southdown" : __DIR__"linhai14",
        "north" : __DIR__"xiaolu2",
    ]));

    setup();
    replace_program(ROOM);
}
