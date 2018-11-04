
inherit ROOM;
void create()
{
    set("short", "柏树林");
    set("long",@LONG
这里是一片枝繁叶茂的柏树林，花草长得便地都是，看着这原始
的密林，你似乎迷失了方向。
LONG
);
    set("exits", ([
       "northeast" :__DIR__"boshulin1",
       "southeast" :__DIR__"boshulin2",
       "east" :__DIR__"boshulin1",
       "north" :__DIR__"boshulin1",
       "south" :__DIR__"boshulin1",
       "northwest" :__DIR__"boshulin1",
       "southwest" :__DIR__"boshulin1",
       "west" :__DIR__"ca27",
]));
    setup();
    replace_program(ROOM);
}
