//Cracked by Kafei
// group bwdh/room 11
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
        "west"      : __DIR__"room_02",
        "south"     : __DIR__"room_12",
        "northeast" : __DIR__"room_10",
    ]));
    create_room();
    setup();
}

void init() {
    init_room();
}
