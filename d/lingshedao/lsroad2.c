//Room:/d/lingshedao/lsroad2.c
inherit ROOM;
void create()
{
        set("short", "ɽ��С��");
        set("long", "����һ����ʯС·,�����͵�ɽ����.\n");
        set("exits", ([
                "southeast"    : __DIR__"lsroad1",
                "northup"  : __DIR__"shangang",
        ]));
        set("no_clean_up",0);
        set("outdoors","lingshedao");
        setup();
        replace_program(ROOM);
}
