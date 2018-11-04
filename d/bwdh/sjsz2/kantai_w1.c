//Cracked by Kafei
// group bwdh/room kantai west
// Apache 09/27/98

#include <ansi.h>
inherit ROOM;
#include "kantai.h"
#include "entrance.h"

void create() {
    set("short", "����̨");
    set("long", @LONG
�����Ǳ��䳡������̨���μӱ����ѡ��Ҳ��
�����볡�������Ѿ����������У�Ⱥ�����۷׷ף�
���ڲ²��ĸ��Ŷ����۹�������Щ����(desk)��
LONG
    );
    set("exits", ([
        "north" : __DIR__"kantai_w2",
        "south" : __DIR__"kantai_w3",
//        "east"  : __DIR__"west_xiangfang",
    ]));
    create_kantai();
    setup();
}

void init() {
    object me = this_player();

    init_kantai();
    if ( me->query("id") == "sheying shi")
        destruct(me);
    else if ( me->query("sjsz/fighting") )
        out_xiangfang();
}

int valid_leave(object me, string dir) {
    if( dir == "east" ) {
        if(wizardp(me) || me->query("sjsz/entrance") == "west" ) {
            go_xiangfang();
            return ::valid_leave(me, dir);
        }
        else
            return notify_fail("ֻ��ָ���Ĳ���ѡ�ֲſ���ȥ���\n");
    }            

	return ::valid_leave(me,dir);
}