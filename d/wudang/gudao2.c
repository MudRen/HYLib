// /d/wudang/gudao2.c  �ŵ�

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",HIG"�ŵ�"NOR);
        set("long", @LONG
�����Źŵ�����������ľ��������ľ���ƣ�����Ұ�޵��������ã������
Ϊ�ϻ�����͵Ļ����ǸϿ��뿪�ĺá�
LONG                           
        );
        set("exits", ([
                "southup" : __DIR__"husunchou",
                "northdown":__DIR__"gudao3",
                "westdown":__DIR__"gudao1",
        ]));

        set("objects",([
                __DIR__"npc/laohu" : 1,

        ]));
        setup();
        replace_program(ROOM);

}

