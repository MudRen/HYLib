//Cracked by Kafei
// group bwdh/room 21
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
        "north"     : __DIR__"room_20",
        "east"      : __DIR__"room_28",
        "south"     : __DIR__"room_22",
    ]));
    create_room();
    set("bwdhpk",1);setup();
}

void init() {
    init_room();
}
