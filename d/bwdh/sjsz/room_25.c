//Cracked by Kafei
// group bwdh/room 25
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
        "west"      : __DIR__"room_23",
        "south"     : __DIR__"room_26",
    ]));
    create_room();
    setup();
}

void init() {
    init_room();
}
