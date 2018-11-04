// Room: /d/xingxiu/silk3c.c
// Jay 3.17/96
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", WHT"����Ȫ"NOR);
        set("long", @LONG
�����������֮�⣬��ɳĮ�о�Ȼ��һ�������ε�Ȫˮ�������ӻأ�ˮ��
�������峺���ס�������������㡢���ǲݣ�������������Ȫ������ɳɽȺ�У�
����ɳ�ɣ�����Ȫ�������Ӳ�����Ȫ�ڡ�������һƬ�ͱ�(cliff) �����ߴ�����
�˵����졣
LONG
        );
        set("resource/water", 1);
       set("outdoors","yili");

        set("exits", ([
//                "west" : __DIR__"silk7a",
                "southeast" : __DIR__"silk3b",
        ]));

        set("item_desc", ([
                "cliff" : "�ͱ����ƺ���һ����(hole)��\n"
        ]) );

        setup();
//        replace_program(ROOM);
}


void init()
{
        add_action("do_enter", "enter");
}
int do_enter(string arg)
{
        object me;
        me = this_player();

        if(!arg || arg=="" ) return 0;
        if(arg=="hole"){
            if(me->query_temp("ride_horse"))
                        return notify_fail("���������ܽ�ȥ��\n");

                        if(me->query_encumbrance() * 100 / me->query_max_encumbrance() < 20){
               message("vision",me->name()+"һ����Ծ���˶��\n",environment(me), ({me}));
               me->move(__DIR__"mogaoku");
               message("vision",me->name()+"�Ӷ������˽�����\n",environment(me), ({me}));
               return 1;
               }
            else{
               write("�����ϱ��Ķ���̫�أ�������̫�ߣ��㹻���š�\n");
               return 1;
               }
        }
}

