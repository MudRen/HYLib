// This is a room made by wsl.

inherit ROOM;

void create()
{
    set("short", "ɽ·");
    set("long",@LONG
����һ����ɽ��С·��
LONG
);
        set("outdoors","changan");
    set("exits", ([
       "westup":__DIR__"ca25",
       "eastdown":__DIR__"ca27",
]));
    setup();
    replace_program(ROOM);
}
