//ROOM xiaodao1.c

inherit ROOM;

void create()
{
	set("short", "小道");
        set("long",@LONG
一条小道蜿延曲折地通向远方, 两旁是郁郁葱葱的树林，微风吹过，
树叶发出奚索的声音。
LONG );
	set("outdoors", "lingjiu");
        set("exits", ([
            "north" : __DIR__"xiaodao2",
            "south" : __DIR__"huayuan",
        ]));
        set("objects",([
            "/d/baituo/npc/cungu" : 1,
	]));
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
