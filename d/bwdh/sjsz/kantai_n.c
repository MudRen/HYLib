//Cracked by Kafei
// group bwdh/room kantai north
// Apache 09/27/98

#include <ansi.h>
inherit ROOM;
#include "kantai.h"

void create() {
    set("short", "����̨");
    set("long", @LONG
�����Ǳ��䳡�ı���̨�������Ѿ���������
�У�Ⱥ�����۷׷ף����ڲ²��ĸ��Ŷ����۹�
������Щ����(desk)��
LONG
    );
    set("exits", ([
        "south"  : __DIR__"square",
        "west"  : __DIR__"kantai_w4",
        "east"  : __DIR__"kantai_e4",
    ]));
    create_kantai();
    setup();
}

void init() {
    init_kantai();
}
