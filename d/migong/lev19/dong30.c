
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"天空之斗技场"NOR);
	set("long", HIC @LONG
   这是一个建在高山上的城堡，墙壁及地板都是以大理石铺设成 墙上
正有几只火把燃烧著，而天花板上则有许多的奇怪的小孔，应该是此城
堡的通风孔，由四周的景物看来此地必定有千年以上的历史，但是景物
依旧且空气清新.这里是斗技场。你可以在这个地方挑战这个世界的各种怪物!!
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
