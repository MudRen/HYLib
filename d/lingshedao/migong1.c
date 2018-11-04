//Room:/d/lingshedao/migong1.c
inherit ROOM;
#include <ansi.h>
void create()
{ 
        set("short", "ɽ��");
        set("long",@LONG
ɽ·��������,����û���˳���,�Ĵ����Ǿ����ʹ���,�㲻
��һ�����.��,��.�ƺ�ֻ������,����������ҵ���·.
LONG );
        set("outdoors", "lingshedao");
        set("exits", ([
                "east" :  __FILE__,
                "west" :  __FILE__,
                "southdown" : __FILE__,
                "northup" : __FILE__,
        ]));             
        set("no_clean_up", 0);
        setup();
}


void init()
{
    object ob=this_player();
    ob->receive_damage("qi", 25);
    ob->receive_wound("qi",  25);
    message_vision(HIR"$N����һʹ,�����������.ԭ�����Ͼ�Ȼ�������߰˴糤�ĸ���\n"NOR,ob);
}

int valid_leave(object me, string dir)
{
        int total_steps,total_steps2;
        total_steps = 30;
        total_steps2 = -30;
        if ( dir == "northup")
            me->add_temp("lsmigong/steps",1); 
        if ( dir == "southdown")
            me->add_temp("lsmigong/steps",-1);
        if (me->query_temp("lsmigong/steps") >= total_steps )
        {  
            me->move(__DIR__"xiaowuout");   
            me->delete_temp("lsmigong/steps");
            return notify_fail("��ҧ�����أ����ڷ���һ��С��,���˳�����\n");
             }
        if (me->query_temp("lsmigong/steps") <= 0 )
        {  
            me->move(__DIR__"shanyao");   
            me->delete_temp("lsmigong/steps");
            return notify_fail("��ҧ�����أ����ڷ���һ��С��,���˳�����\n");
             }

        return ::valid_leave(me,dir);
}
