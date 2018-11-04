
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", YEL"大地之斗技场"NOR);
	set("long", HIG @LONG
   矮人国度的主要道路,道路的两旁有火把照亮著,由於矮人高超的建筑
技术,这道路修筑的非常笔直 , 很难相信你是处在地底下数十里的地方 .
这里有著非常和平安详的气氛,恍佛是一个世外桃源.这里已经多年没有战
争了。这里是斗技场。你可以在这个地方挑战这个世界的各种怪物!!
LONG NOR);

set("magicroom",1);set("outdoors","migong");
set("magicset",1);

set("sleep_room",1);
	set("exits", ([
                "south" : __DIR__"dong29",
	]));
         set("objects", ([
              __DIR__"npc/lev"+(random(5)+5) : 1,
              __DIR__"npc/lev"+(random(6)+4) : 1,
              __DIR__"npc/lev"+(random(8)+2) : 1,
              __DIR__"npc/lev"+(random(9)+1) : 1,
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
