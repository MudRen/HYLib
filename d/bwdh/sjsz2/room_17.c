//Cracked by Kafei
// group bwdh/room 17
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
		  "north"     : __DIR__"room_16",
		  "west"     : __DIR__"room_26",
		  "south"     : __DIR__"room_18",
	 ]));
    create_room();
    setup();
}

void init() {
    init_room();
}
