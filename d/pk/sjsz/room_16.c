//Cracked by Kafei
// group bwdh/room 16
// Apache 09/27/98

#include <ansi.h>
inherit ROOM;
#include "sjsz_room.h"

void create() {
    set("short", HIM"����"NOR);
    set("long", @LONG
�����Ǳ��䳡�Ķ��������ܾ����ĵġ��������Ѿ�����
��һ��ɱ����ʹ��е�����������
LONG
    );
    set("exits", ([
        "north"     : __DIR__"room_15",
        "east"      : __DIR__"room_05",
        "south"     : __DIR__"room_17",
    ]));
    create_room();
    set("bwdhpk",1);setup();
}

void init() {
    init_room();
}
