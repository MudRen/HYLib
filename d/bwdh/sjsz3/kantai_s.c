//Cracked by Kafei
// group bwdh/room kantai south
// Apache 09/27/98

#include <ansi.h>
inherit ROOM;
#include "kantai.h"

void create() {
    set("short", "�Ͽ�̨");
    set("long", @LONG
�����Ǳ��䳡���Ͽ�̨�������Ѿ���������
�У�Ⱥ�����۷׷ף����ڲ²��ĸ��Ŷ����۹�
������Щ����(desk)��
LONG
    );
    set("exits", ([
        "north" : __DIR__"square",
        "west"  : __DIR__"kantai_w5",
        "east"  : __DIR__"kantai_e5",
    ]));
    create_kantai();
    setup();
}


void init() {
    init_kantai();
}
