// This is a room made by wsl.

inherit ROOM;

void create()
{
    set("short", "ɽ·");
    set("long", @LONG
һ����ȥ��ǰ��һƬ�����������˸����Ӳݣ��ƺ�����ɱ����
LONG
);
        set("outdoors","changan");
    set("exits", ([
       "westup":__DIR__"ca26",
       "east":__DIR__"boshulin1",
]));
    setup();
    replace_program(ROOM);
}
