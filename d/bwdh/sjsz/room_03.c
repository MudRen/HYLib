//Cracked by Kafei
// group bwdh/room 03
// Apache 09/27/98

#include <ansi.h>
inherit ROOM;
#include "sjsz_room.h"

void create() {
    set("short", HIG"��ƫ��"NOR);
    set("long", @LONG
�����Ǳ��䳡����ƫ�����տ��Ĵ�����һ���ܺõ�����ط���
LONG
    );
    set("exits", ([
        "south"  : __DIR__"room_04",
        "north"  : __DIR__"room_02",
        "west"   : __DIR__"room_01",
    ]));
    create_room();
    setup();
}

void init() {
    init_room();
}
