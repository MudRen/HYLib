// xtj 
// by dubei

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
    set("short", BLU "С��"NOR);
    set("long", @LONG
����ɽ��֮������춶��������ƺ����ٲ��ܽ��ˡ�
LONG
    );

    set("outdoors", "xiangyang");

    set("exits", ([
        "south" : __DIR__"xiaolu1",
        "northwest" : __DIR__"pubu",
    ]));

    setup();
    replace_program(ROOM);
}
