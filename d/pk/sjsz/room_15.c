//Cracked by Kafei
// group bwdh/room 15
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
        "south"     : __DIR__"room_16",
        "southwest" : __DIR__"room_25",
    ]));
    create_room();
    set("bwdhpk",1);setup();
}

void init() {
    init_room();
}
