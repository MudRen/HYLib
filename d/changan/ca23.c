// This is a room made by wsl.

inherit ROOM;

void create()
{
    set("short", "С��");
    set("long",@LONG
һ������ש�ҳɵ�С�������������������Եð�������ࡣ
���������ϣ���һƬĹ־�����ı��֡�
LONG
);
        set("outdoors","changan");
    set("exits", ([
       "north":__DIR__"ca18",
       "south":__DIR__"ca16",
]));
    setup();
    replace_program(ROOM);
}
