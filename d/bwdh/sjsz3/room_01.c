//Cracked by Kafei
// group bwdh/room 01
// Apache 09/27/98

#include <ansi.h>
inherit ROOM;
#include "sjsz_room.h"

void create() {
	 set("short", HIG"�ݵ�"NOR);
	 set("long", @LONG
������һ��Ƭ�տ��Ĳݵء������ĵ�������ҫ�£�������������ƽ�͵����ա�
LONG
    );
    set("exits", ([
        "east" : __DIR__"room_03",
        "up" : __DIR__"wtower1",
        "west" : __DIR__"wgarden",
	 ]));
    create_room();
    setup();
}

void init() {
    init_room();
}
