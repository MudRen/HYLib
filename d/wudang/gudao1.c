// /d/wudang/gudao1.c  �ŵ�

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",HIG"�ŵ�"NOR);
        set("long", @LONG
������һ���˼������Ĺŵ��ϣ�����Ұ�ݹ�����·��ʱ��ʱ�֣�������ͷ
����ʱ�����е�����һ������! �����ϵ��������ߣ��������������ϣ�
һ���Ⱥ����ͷ��������һ��һ�£��ò����ˡ�
LONG                           
        );
        set("exits", ([
                "eastup" : __DIR__"gudao2",
                "westdown" : __DIR__"shanlu",
        ]));

        set("objects",([
                __DIR__"npc/dushe" : 1,

        ]));

        setup();
        replace_program(ROOM);

}

