// This is a room made by wsl.

inherit ROOM;

void create()
{
    set("short", "���");
    set("long",@LONG
һ����ʯ�̾͵���������죬������������ľ�����Ͼ��ǳ���
���ˡ�
LONG
);
        set("outdoors","changan");
    set("exits", ([
       "south":__DIR__"ca9",
       "north":__DIR__"ca28",
       "eastup":__DIR__"ca24",
       "west":__DIR__"ca22",
]));
    setup();
    replace_program(ROOM);
}
