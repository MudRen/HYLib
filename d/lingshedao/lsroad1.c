//Room:/d/lingshedao/lsroad1.c
inherit ROOM;
void create()
{
        set("short", "ɽ��С��");
        set("long", @LONG
����һ����ʯС·,������ï�ܵ�����,������ͨ��һ��
�߸ߵ�ɽ��.
LONG);
        set("exits", ([
                "northwest"    : __DIR__"lsroad2",
                "eastup"  : __DIR__"lsroad3",
                "southwest" : __DIR__"haitan1",  ]));
        set("no_clean_up",0);
        set("outdoors","lingshedao");
        setup();
        replace_program(ROOM);
}
