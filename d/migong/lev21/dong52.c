
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIG"诱惑的宫殿"NOR);
	set("long",RED @LONG
本来这里是一座城市，因为当时的一场灾难把这座城
市的人都给毁灭了。你突然发现，周围的墙壁是用纯金
砌成的。一种无比的诱惑使你继续前进。 
LONG NOR);

set("magicroom",1);set("outdoors","migong");
set("magicset",1);

	set("exits", ([
		"westdown" : __DIR__"dong53",
		"eastup" : __DIR__"dong5"+(random(4)+1),
		"southwest" : __DIR__"dong5"+(random(4)+1),
		"northeast" : __DIR__"dong5"+(random(4)+1),
	]));
if (random(3)==0)
	set("exits", ([
		"south" : __DIR__"dong51",
		"north" : __DIR__"dong53",
	]));
if (random(3)==0)
	set("exits", ([
		"east" : __DIR__"dong51",
		"west" : __DIR__"dong53",
	]));

if (random(3)==0)
	set("exits", ([
		"west" : __DIR__"dong5"+(random(4)+1),
		"east" : __DIR__"dong5"+(random(4)+3),
		"south" : __DIR__"dong5"+(random(4)+1),
		"north" : __DIR__"dong5"+(random(4)+1),
	]));
        set("objects", ([
              __DIR__"npc/lev2" : 5,
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

