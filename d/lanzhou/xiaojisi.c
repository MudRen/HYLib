// Room: /wizhome/lanzhou/xiaojisi.c
// Data: xws 98/10/14

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "С����");
        set("long", @LONG
���������ݳǵ�һ��С���С��ϱ���һ���ϾƵ꣬��ʱ����һ������㡣��
�����������������Ľ�ͨҪ�������۵���������ԭ��Ҫ����������Ը��ص�
���������������㲻ʱ���Կ���һЩ�˴��������������߾�����

LONG
        );
        set("no_sleep_room",1);
        set("outdoors", "lanzhou");


        set("exits", ([
                "south"  : __DIR__"jioudian",
                "north"  : __DIR__"xidajie1",
        ]));

        set("objects", ([
        __DIR__"npc/liumang" : 2,
        __DIR__"npc/liumangtou" : 1,    
       	]));

        setup();
}
