 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "��");
        set("long", @LONG
Ӣ�۶������ԡ��ϲ�ȴ�����⣬���Ӳ������������ֻ���������Ĺ��ߡ�
��������������������˲�������˶����������ÿƥ�������úܽ�����ͷ
����ƥ�������ձ���������ʱ���Գ�����
LONG
        );
        set("exits", ([ 
                "east" :   __DIR__"garden3",
        ]));
        set("objects", ([
                __DIR__"npc/fenghao":   1,
        ]) );
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
} 
