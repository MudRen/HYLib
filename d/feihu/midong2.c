//�ܶ��� 
// by steel 
// change by wind
#include "ansi.h"
inherit ROOM;
//#include "mimi.h"
void create()
{
        object gold;
        set("short", "�ڶ�");
        set("long", @LONG
        ������Ƕѷ������ܱ����ܶ���!!���ð�!    
�����̵�����.(zi)
LONG
        );
set("valid_startroom", 1);
set("no_clean_up",1);
set("no_quit",1);
        set("exits", ([
                "north" : __DIR__"midong",
                ]));
    set("item_desc",([
                "zi" : HIR "
                   ��     ��
                   Ϊ     Ϊ 
                   ��     ʳ
                   ��     �� 
                   \n\n"NOR,
        ]));   

   
        set("objects",([
            __DIR__"obj/cw_armor":1,
            __DIR__"obj/cw_boots":1, 
            __DIR__"obj/cw_cloth":1,
            __DIR__"obj/cw_hat" :1,
            __DIR__"obj/book-blade":1,
            __DIR__"obj/book-parry":1,
                     __DIR__"npc/corpse":5,
        ]) );
 setup();
} 

int valid_leave(object me, string dir)
{
        int num_dia,num_fei,total_steps;
        object gold,feicui;

 gold=present("diamond",this_object());
        return ::valid_leave(me,dir);
}
