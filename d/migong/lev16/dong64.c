#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", RED"灼热的深渊"NOR);
	set("long", RED @LONG
  毒气，硫磺！这是一片火红的大地，灼热的地面上
升起一阵一阵的毒烟!无际的大沙漠。而四下的怪物
更是对你虎视眈眈，随时都会扑过来，咬断你的咽喉
，撕裂你的身躯。
LONG NOR);
set("magicroom",1);
set("magicset",1);

	set("exits", ([
		"west" : __DIR__"dong3"+(random(5)+3),
		"east" : __DIR__"dong4"+(random(5)+1),
		"south" : __DIR__"dong65",
		"north" : __DIR__"dong63",
	]));
if (random(3)==0)
	set("exits", ([
		"west" : __DIR__"dong64",
		"east" : __DIR__"dong6"+(random(5)+1),
		"south" : __DIR__"dong6"+(random(5)+5),
		"north" : __DIR__"dong6"+(random(5)+1),
	]));
        set("objects", ([
              __DIR__"npc/lev6" : 3,
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
