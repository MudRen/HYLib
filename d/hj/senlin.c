// senlin.c
#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
       set("short","��Ҷ��");
       set("long", "
���Ǽ�����ɽ���µ�һƬ��Ҷ�֣��������޳�Ⱥ�������̸��ź��һ
�����롣��������һ�����ʵ�ɽ��������ɽ�ˣ�ɽ�������ѩ��ɽ��ȴ��
���������������߱��Ǵ��ԭ�������ڵĹ��������������������\n");

        set("exits", ([
                "north" : "/d/xingxiu/shanjiao",
                "southeast" : __DIR__"shanqiu",
        ]));
        
        set("objects", ([
                         __DIR__"npc/bird" : 1,
        ]));

        set("outdoors", "tianshan");

        setup();
       replace_program(ROOM);
}