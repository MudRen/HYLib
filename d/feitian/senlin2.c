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
        
        set("objects", ([
                         __DIR__"npc/wolf" : 1,
        ]));

        set("outdoors", "feitian");
        setup();           
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