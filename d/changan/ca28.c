// This is a room made by wsl.

inherit ROOM;

void create()
{
    set("short", "���");
    set("long", @LONG
һ����ʯ�̾͵�������ϱ����죬������������ľ��
LONG
);
        set("outdoors","changan");
    set("exits", ([
       "south":__DIR__"ca21",
]));
    setup();
    replace_program(ROOM);
}
