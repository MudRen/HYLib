//Cracked by Kafei
// group bwdh/room 09
// 

#include <ansi.h>
inherit ROOM;
#include "sjsz_room.h"

void create() {
	 set("short", HIW"ɽ��"NOR);
	 set("long", @LONG
������һ�����͵�ɽ����ͨ���վ���ɽ�塣���������Ҫ������һ�ذѵ������Ī�С�
LONG
    );
    set("exits", ([
        "west"      : __DIR__"room_07",
        "up"      : __DIR__"etower1",
        "east"      : __DIR__"egarden",
	 ]));
    create_room();
	 setup();
}

void init() {
	 init_room();
}
