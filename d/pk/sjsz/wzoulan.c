//Cracked by Kafei
// group /d/bwdh/sjsz/wzoulan
// sdong, 8/8/99

#include <ansi.h>
inherit ROOM;
#include "sjsz_room.h"

void create() {
	 set("short", HIG"С��"NOR);
	 set("long", @LONG
������һ������С�����ž������˺��¡�
LONG
	 );
	 set("exits", ([
						"south" : __DIR__"wgarden",
						"east"  : __DIR__"room_02",
								 ]));
    set("outdoors", "city");
	 create_room();
	 set("bwdhpk",1);setup();
}

void init() {
	 init_room();
}
