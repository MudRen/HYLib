//Cracked by Kafei
// group bwdh/room kantai_e3
// Apache 09/27/98

#include <ansi.h>
inherit ROOM;
#include "kantai.h"

void create() {
    set("short", "����̨��");
    set("long", @LONG
�����Ǳ��䳡�Ķ���̨���������Ѿ���������
�У�Ⱥ�����۷׷ף����ڲ²��ĸ��Ŷ����۹���
����Щ����(desk)��
LONG
    );
    set("exits", ([
        "north"  : __DIR__"kantai_e1",
        "southwest" : __DIR__"kantai_e5",
    ]));
    create_kantai();
    setup();
}

void init() {
    init_kantai();
}
