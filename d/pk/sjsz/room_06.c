//Cracked by Kafei
// group bwdh/room 06
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
        "north" : __DIR__"room_05",
        "south" : __DIR__"room_07",
    ]));
    create_room();
    set("bwdhpk",1);setup();
}

void init() {
    init_room();
}
