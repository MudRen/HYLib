// This is a room made by wsl.

inherit ROOM;

void create()
{
    set("short", "ɽ·");
    set("long", @LONG
������һ����ɽ��С·�����ֳ�һ�������������
LONG
);
        set("outdoors","changan");
    set("exits", ([
       "westdown":__DIR__"ca21",
       "northup":__DIR__"ca25",
]));
    setup();
    replace_program(ROOM);
}
