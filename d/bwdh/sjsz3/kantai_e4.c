//Cracked by Kafei
// group bwdh/room kantai_e4
// Apache 09/27/98

#include <ansi.h>
inherit ROOM;
#include "kantai.h"

void create() {
    set("short", "����̨��");
    set("long", @LONG
�����Ǳ��䳡�Ķ���̨�ġ������Ѿ���������
�У�Ⱥ�����۷׷ף����ڲ²��ĸ��Ŷ����۹���
����Щ����(desk)��
LONG
    );
    set("exits", ([
        "west"  : __DIR__"kantai_n",
        "southeast" : __DIR__"kantai_e2",
    ]));
    create_kantai();
    setup();
}

void init() {
    init_kantai();
}
