
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
		set("short", BLU"山洞"NOR);
	set("long", BLU @LONG
 你越走越深，周围的墙壁似乎有些松软了。 
LONG NOR);
	set("exits", ([
		"east" : __DIR__"dong"+(random(18)+3),
		"south" : __DIR__"dong"+(random(13)+3),
                "west" : __DIR__"dong"+(random(8)+3),
                "north" : __DIR__"dong"+(random(3)+3),
	]));
if (random(3)==0)
	set("exits", ([
		"east" : __DIR__"dong"+(random(20)+21),
                "west" : __DIR__"dong"+(random(10)+31),
	]));

if (random(3)==0)
	set("exits", ([
		"south" : __DIR__"dong"+(random(15)+41),
                "north" : __DIR__"dong"+(random(5)+51),
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
