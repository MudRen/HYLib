// senlin.c
#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
       set("short","ԭʼɭ��");
       set("long", @LONG
���Ǿ���ͨ��������һ��ɭ�֣�ɭ���е��²�����һ�������Ҷ����ȥ
�������죬͸��ɭ�ֵ�һЩ���������£����������������㷢���Լ��Ѿ�
��ʧ�˷����㿪ʼ�е����߽����ˡ�
LONG);
        set("exits", ([
             "east"  : __DIR__"senlin"+(1+random(4)),
             "west"  : __DIR__"senlin"+(1+random(4)),
             "south" : __DIR__"senlin"+(1+random(4)),
             "north" : __DIR__"senlin"+(1+random(4)),               
        ]));
        
        set("outdoors", "feitian");
        setup();            
}

void init()
{
        object me = this_player();
        if(userp(me) && me->query("jingli") < 10){
           switch(random(2)) {
            case 0 : me->move(__DIR__"zhongxiandao"); break;
            case 1 : me->move(__DIR__"linzi"); break;
            }
           message_vision("$N����ʧ������˹�����\n",me);
           me->unconcious();
           }
        if(!me->query_temp("corredt_dir") && userp(me))
         me->set_temp("correct_dir", keys(query("exits"))[random(sizeof(query("exits")))]);
}

int valid_leave(object me, string dir)
{
        if( dir != me->query_temp("correct_dir"))
                me->set_temp("ft_sl", 0);
        else    me->add_temp("ft_sl", 1);

        if( me->query_temp("ft_sl") > 5 + random(5) ) {
                me->move(__DIR__"senlin");
                me->delete_temp("ft_sl");
                me->delete_temp("correct_dir");
                return notify_fail("�����˫������һͨ�������ҵ��˷���\n");
        }
        return ::valid_leave(me,dir);
}

