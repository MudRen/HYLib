// qishi.c
inherit ROOM;

void create()
{
        set("short", "棋室");
        set("long", @LONG
这里便是二庄主黑白子的棋室了，棋室里两张石凳，一张石几，
石几上用黑白子的指力刻着纵横九九八十一道，这里除了简单的放着
两盒用玉做成的棋子外，什么都没有，显是怕双方对弈时分心。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
            "east" : __DIR__"zoulang2",
        ]));
        set("objects", ([ /* sizeof() == 1 */
             __DIR__"npc/heibai-zi.c" : 1,
        ]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
