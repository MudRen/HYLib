// /d/wudang/shanlu2.c  ɽ·

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",HIG"ɽ·"NOR);
        set("long", @LONG
������һ��ƫƧ��ɽ·�ϣ����ܹ�ľ�Դԣ�����滨��ݣ��˼�
������·��������Ѱ��ֻ�в�ҩ���˲Ÿҽ�����ɽ���㵽���Ҵ�Ѱ��
��·���͵�һʹ�����������������!
LONG                           
        );
        set("exits", ([
                "eastup" : __DIR__"zixiaogate",
                "south" : __FILE__,
                "west" : __FILE__,
                "north" : __FILE__,
        ]));

        set("no_npc",1);
        set("objects",([
                __DIR__"npc/caiyao" : 1,
        ]));

        setup();
        replace_program(ROOM);

}

int valid_leave(object me, string dir)
{
if( dir == "southeast" )
{
me->start_busy(3);
me->receive_damage("qi", random(10));
me->receive_damage("jing", random(10));
return 1;
}
        return ::valid_leave(me, dir);
}

