#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
		set("short", BLU"ɽ��"NOR);
	set("long", BLU @LONG
 ��Խ��Խ���Χ��ǽ���ƺ���Щ�����ˡ� 
LONG NOR);
	set("exits", ([
		"east" : __DIR__"dong01",
		"south" : __DIR__"dong7"+(random(4)+5),
                "west" : __DIR__"dong88",
                "north" : __DIR__"dong6"+(random(8)+1),
	]));
if (random(6)==1)
	set("exits", ([
		"south" : __DIR__"dong3"+(random(4)+3),
                "north" : __DIR__"dong8"+(random(2)+7),
    "west" : __DIR__"dong3"+(random(9)+1),
    "east" : __DIR__"dong4"+(random(9)+1),
	]));
if (random(9)==0)
	set("exits", ([
		"north" : __DIR__"dong1"+(random(9)+1),
		"south" : __DIR__"dong2"+(random(9)+1),
		"east" : __DIR__"dong01",
                "west" : __DIR__"dong4"+(random(4)+5),
	]));
        
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
