#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
		set("short", RED"熔岩洞入口"NOR);
	set("long", RED @LONG
    滚烫岩浆不断散发着热气，令人喘不过气来，一些前所
未见的巨大生物在这里走动着。 
LONG NOR);
	set("exits", ([
		"east" : __DIR__"dong37",
		"west" : __DIR__"dong04",
                	]));
if (random(3)==0)
	set("exits", ([
		"east" : __DIR__"dong04",
		"west" : __DIR__"dong37",
                "down" : "/d/migong/lev14/dong01",
                	]));
      set("objects", ([
              __DIR__"npc/lev"+(random(9)+1) : 1,
                           ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
