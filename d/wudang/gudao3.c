// /d/wudang/gudao3.c  �ŵ�

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",HIG"�ŵ�"NOR);
        set("long", @LONG
������ͣͣ�������ѵ���·�ľ�ͷ���������ͻ����������ݣ���ֻҰ��
�������������ȥ��������������ʮ��������һˮ̶��̶ˮ�峺�����������
�������ѵ����޲�����������ȥ����һ����
LONG                           
        );
        set("exits", ([
              "southup" : __DIR__"gudao2",
        ]));

        set("objects",([        
                __DIR__"npc/yetu" : 2,
        ]));

        setup();

}

void init()
{
        add_action("do_jump","tiao");
}

int do_jump(string arg)
{       object me,tmp;
        me=this_player();
        if ( !arg || arg != "down" )
            return notify_fail("��Ҫ������?\n");
        if ( me->query("combat_exp") < 100000)
            return notify_fail("�����������������ˮ�����쳣�����������˽š�\n");
        message_vision(HIY"$Nһ�й�����ǽ����֫ƽչ�͵ó�ˮ̶���¡�\n"NOR, me);
        me->move(__DIR__"shuitan");
       message_vision(RED"��ͨһ����$N����������ˮ����������һ�󷭹���������Ҫ���������๾�࣬
����������һ����ˮ��\n"NOR, me);
        me->receive_damage("jing", 20);
        me->set("water", me->max_water_capacity()+200);
         return 1;
}
