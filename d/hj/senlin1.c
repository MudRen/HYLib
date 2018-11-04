// senlin.c
#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
       set("short","��Ҷ��");
       set("long", @LONG
���Ǽ�����ɽ���µ�һƬ��Ҷ�֣��������޳�Ⱥ�������̸��ź��һ
�����롣������һ�����ʵ�ɽ��������ɽ�ˣ�ɽ�������ѩ��ɽ��ȴ����
�����������߱��Ǵ��ԭ�������ڵĹ����������������������������
�ţ���Ȼ��ʧ�˵�·��
LONG);
        set("exits", ([
             "east"  : __DIR__"senlin"+(1+random(4)),
             "west"  : __DIR__"senlin"+(1+random(4)),
             "south" : __DIR__"senlin"+(1+random(4)),
             "north" : __DIR__"senlin"+(1+random(4)),               
        ]));
        
        set("outdoors", "tianshan");
        setup();            
}

void init()
{
        object me = this_player();
        if(userp(me) && me->query("jingli") < 10){
           switch(random(2)) {
            case 0 : me->move(__DIR__"shanqiu"); break;
            case 1 : me->move("/d/xingxiu/shanjiao"); break;
            }
           message_vision("$N�����������˹�����\n",me);
           me->unconcious();
           }
        if(!me->query_temp("corredt_dir") && userp(me))
         me->set_temp("correct_dir", keys(query("exits"))[random(sizeof(query("exits")))]);
}

int valid_leave(object me, string dir)
{
        if( dir != me->query_temp("correct_dir"))
                me->set_temp("ts_sl", 0);
        else    me->add_temp("ts_sl", 1);

        if( me->query_temp("ts_sl") > 5 + random(5) ) {
                me->move(__DIR__"senlin");
                me->delete_temp("ts_sl");
                me->delete_temp("correct_dir");
                return notify_fail("���۵ð���������ҵ�����ȷ�ķ���\n");
return 1;
        }
        return ::valid_leave(me,dir);
}

