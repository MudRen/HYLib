
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"风化之家"NOR);
	set("long", HIY @LONG
   这这个地方,风势十分的强劲,附近有一团雾却是依旧滞留著,而且有
逐渐扩散的趋势,你已经无法看到附近的地形了,必须小心翼翼的站著以
免被强劲的风势吹进那个看不见的深渊.
LONG NOR);
set("magicroom",1);set("outdoors","migong");
set("magicset",1);
	set("exits", ([
		"south" : __DIR__"dong45",
                "north" : __DIR__"dong3"+(random(6)+4),
		"west" : __DIR__"dong42",
                "east" : __DIR__"dong3"+(random(9)+1),
	]));
if (random(3)==0)
	set("exits", ([
		"south" : __DIR__"dong4"+(random(6)+1),
                "north" : __DIR__"dong3"+(random(6)+4),
		"west" : __DIR__"dong4"+(random(4)+4),
                "east" : __DIR__"dong3"+(random(6)+4),
	]));
if (random(2)==0)
	set("exits", ([
		"east" : __DIR__"dong45",
                "west" : __DIR__"dong3"+(random(6)+4),
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

