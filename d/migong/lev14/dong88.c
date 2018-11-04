#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{	
       set("short", RED"熔岩洞"NOR);
	set("long", RED @LONG
    滚烫岩浆不断散发着热气，令人喘不过气来，一些前所
未见的巨大生物在这里走动着。 
LONG NOR);
	set("exits", ([
		"east" : __DIR__"dong1"+(random(3)+1),
		"south" : __DIR__"dong3"+(random(5)+1),
                "west" : __DIR__"dong5"+(random(2)+5),
                "north" : __DIR__"dong89",
	]));
if (random(6)==1)
	set("exits", ([
		"south" : __DIR__"dong8"+(random(2)+8),
                "north" : __DIR__"dong4"+(random(4)+3),
    "west" : __DIR__"dong3"+(random(9)+1),
    "east" : __DIR__"dong4"+(random(9)+1),
	]));
if (random(9)==0)
	set("exits", ([
		"east" : __DIR__"dong1"+(random(6)+1),
                "west" : __DIR__"dong8"+(random(2)+6),
		"north" : __DIR__"dong1"+(random(9)+1),
		"south" : __DIR__"dong2"+(random(9)+1),
	]));
         set("objects", ([
              __DIR__"npc/lev"+(random(9)+1) : 2,
             __DIR__"npc/lev"+(random(9)+1) : 2,
             "/d/migong/obj/npc1" : random(3),
                ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
