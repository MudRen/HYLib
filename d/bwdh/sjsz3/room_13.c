//Cracked by Kafei
// group bwdh/room 13
// Apache 09/27/98

#include <ansi.h>
inherit ROOM;
#include "sjsz_room.h"

void create() {
    set("short", HIM"����"NOR);
    set("long", @LONG
�����Ǳ��䳡�����������ܾ����ĵġ��������Ѿ�����
��һ��ɱ����ʹ��е�����������
LONG
    );
    set("exits", ([
        "west"      : __DIR__"room_04",
        "north"     : __DIR__"room_12",
        "southeast" : __DIR__"room_14",
    ]));
    create_room();
    setup();
}

void init() {
    init_room();
}
