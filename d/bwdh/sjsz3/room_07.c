//Cracked by Kafei
// group bwdh/room 07
// Apache 09/27/98

#include <ansi.h>
inherit ROOM;
#include "sjsz_room.h"

void create() {
    set("short", HIG"��ƫ��"NOR);
    set("long", @LONG
�����Ǳ��䳡�Ķ�ƫ�����տ��Ĵ�����һ���ܺõ�����ط���
LONG
    );
    set("exits", ([
        "east"  : __DIR__"room_09",
        "north" : __DIR__"room_06",
        "west"  : __DIR__"room_18",
    ]));
    create_room();
    setup();
}

void init() {
    init_room();
}
