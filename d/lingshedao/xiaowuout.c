//Room:/d/lingshedao/xiaowuout.c
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "�յ�");
        set("long",@LONG
��������һƬ�յ�,ǰ����һ��Сé��,����û��һ�����,
��֪��ס��˭.
LONG );
        set("exits", ([
                "enter"    : __DIR__"xiaowu",
                "southdown"  : __DIR__"migong1",
        ]));

        set("objects",([
                //__DIR__"npc/han" : 1,
        ]));

       set("no_clean_up",0);
        set("outdoors","lingshedao");
        setup();

}

int valid_leave(object me,string dir)
{
        if( ( dir=="enter" )
             &&objectp(present("jin hua",environment(me)))
             &&((int)me->query("shen")>100000) )
             return notify_fail
                    ("�����������˵��:�����������ߵ������ô?��������������˵����
ȴ��Ҫȥɧ�����ߵ��Ĺ��.\n");
       else if(  (dir=="enter")
             &&objectp(present("jin hua",environment(me)))
             &&(me->query("party/party_name")== HIG "����" NOR)) 
             return notify_fail
             ("�����Ŵ��һ��:��С��,��������������?Ҫ���ǿ���
�������̵��ӵķ���,�ұ㽫��ɱ��,����ҹ�!\n");
      else  if( (dir == "enter") && objectp(present("jin hua",environment(me))) )
            {
             me->set_temp("nk",1);
             return notify_fail
                    ("�����źߵ�һ��˵��:�ҵ����ߵ�����Ұ,��ò��ͷ���!���,�����ҿ����ڶ���\n");
            }
       return ::valid_leave(me,dir);
}
