//Room:/d/lingshedao/lsroad4.c
inherit ROOM;
void create() {          set("short", "ɽ��С��");
        set("long", @LONG
����һ����ɽ��·,͸����֦�ļ�϶,������������ε����
��.
LONG );
        set("exits", ([
                "westup"    : __DIR__"shanyao",
                "eastdown"  : __DIR__"lsroad5",
        ]));
        set("no_clean_up",0);
        set("outdoors","lingshedao");   
        setup();
        replace_program(ROOM);
}
