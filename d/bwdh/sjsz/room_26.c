//Cracked by Kafei
// group bwdh/room 26
// Apache 09/27/98

#include <ansi.h>
inherit ROOM;
#include "sjsz_room.h"

void create() {
    set("short", HIR"����"NOR);
    set("long", @LONG
�����Ǳ��䳡��������ɱ��Խ��ԽŨ�ˡ�Զ������
����΢�ĺ�������ż������Ӱһ�����������ƺ��о���
�м�˫�۾��ڶ�����ӡ�
LONG
    );
    set("exits", ([
        "north"     : __DIR__"room_25",
        "west"      : __DIR__"room_28",
        "east"      : __DIR__"room_17",
		  "south"     : __DIR__"room_27",
    ]));
    create_room();
    setup();
}

void init() {
    init_room();
}
