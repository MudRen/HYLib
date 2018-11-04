//Cracked by Kafei
// group bwdh/room 14
// Apache 09/27/98

#include <ansi.h>
inherit ROOM;
#include "sjsz_room.h"

void create() {
    set("short", HIM"西厅"NOR);
    set("long", @LONG
这里是比武场的西厅，四周静悄悄的。空气中已经弥漫
者一股杀气，使你感到不寒而栗。
LONG
    );
    set("exits", ([
        "north"     : __DIR__"room_22",
        "northwest" : __DIR__"room_13",
    ]));
    create_room();
    set("bwdhpk",1);setup();
}

void init() {
    init_room();
}
