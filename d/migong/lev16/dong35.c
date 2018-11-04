
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", YEL"永恒的沙漠"NOR);
	set("long", YEL @LONG
  由于火元素的影响，这附近全是砂漠，这是一片一望
无际的大沙漠。你一进来就迷失了方向。看来要走出这
块沙漠并非易事。
LONG NOR);
set("magicroom",1);
set("magicset",1);
	set("exits", ([
		"east" : __DIR__"dong3"+(random(4)+5),
		"south" : __DIR__"dong3"+(random(3)+5),
                "west" : __DIR__"dong3"+(random(3)+5),
                "north" : __DIR__"dong3"+(random(4)+5),
	]));
if (random(3)==0)
	set("exits", ([
		"east" : __DIR__"dong3"+(random(4)+5),
                "west" : __DIR__"dong3"+(random(4)+5),
	]));

         set("objects", ([
              __DIR__"npc/lev1" : random(5),
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

