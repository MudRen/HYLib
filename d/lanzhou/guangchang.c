// Room: /wizhome/lanzhou/guangchang.c
// Data: xws 98/10/13

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "����㳡");
        set("long", @LONG
���������ݳǵ�����㳡���������������������Ľ�ͨҪ�������۵�����
����ԭ��Ҫ����������Ը��ص����������������㲻ʱ���Կ���һЩ��������
�����նӴҴ�����ȥ��
�����ǳ��е������ģ���һ���ܿ����Ĺ㳡�����������ɳ�ܴ���������
��ʯ�ĵ��澭������һ���ɳ��һЩ���ֺ��е��������������������һЩ
����������������ݡ���������������ԭ����������һ����ǣ����ص����˶�
������������Ĳ����������������У����С�����������˶������Լ�����Ʒ��
һ�����־���
LONG
        );
        set("no_sleep_room",1);
        set("outdoors", "lanzhou-city");


        set("exits", ([
                "east"   : __DIR__"dongdajie1",
                "south"  : __DIR__"nandajie1",
                "west"   : __DIR__"xidajie1",
                "north"  : __DIR__"beidajie1",
        ]));

        set("objects", ([
        __DIR__"npc/liumang" : 2,
        __DIR__"npc/liumangtou" : 1,    
        __DIR__"npc/xiaofan" : 1,
  	]));

        setup();
}
