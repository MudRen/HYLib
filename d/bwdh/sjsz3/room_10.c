//Cracked by Kafei
// group bwdh/room 10
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
        "south"     : __DIR__"room_20",
        "southwest" : __DIR__"room_11",
    ]));
    create_room();
    setup();
}

void init() {
    init_room();
}
