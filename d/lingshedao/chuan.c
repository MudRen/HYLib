//Room:/d/lingshedao/chuan.c
inherit ROOM;
void create()
{
        set("short", "ս��");
        set("long", @LONG
����һ�Ҿ޴��ս��,����ս��Ʈ��,���ܶ��ǻ���.
LONG );
 //       set("exits", ([
 //               "out"    : __DIR__"xiaowuout",
 //       ]));
        set("objects",([
                __DIR__"npc/liuyun" : 1,
                __DIR__"npc/huiyue" : 1,
                __DIR__"npc/miaofeng" : 1,               
        ]));
        set("no_clean_up",0);
 //       set("outdoors","lingshedao");
        setup();
        replace_program(ROOM);
}
