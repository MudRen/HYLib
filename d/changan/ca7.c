// This is a room made by wsl.
inherit ROOM;
void create()
{
    set("short", "�����Ǵ��");
    set("long",@LONG
����һ�����ַǷ���������һ��С���������ϡ�١����治ʱ
�������������������ԭ���Ǽ�����̡�
LONG
);
        set("outdoors","changan");
        set("exits", ([
         "west" :__DIR__"garments",
         "east" :__DIR__"ca8",
         "southwest" :__DIR__"taibaitang",
         "south" :__DIR__"ca",
         "north" :__DIR__"ca9",
]));
    setup();
    replace_program(ROOM);
}
