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
		"east" : __DIR__"dong03",
		"south" : __DIR__"dong4"+(random(4)+5),
                "west" : __DIR__"dong5"+(random(4)+5),
                "north" : __DIR__"dong68",
	]));
if (random(6)==1)
	set("exits", ([
		"south" : __DIR__"dong4"+(random(4)+3),
                "north" : __DIR__"dong6"+(random(2)+7),
	]));
if (random(9)==0)
	set("exits", ([
		"east" : __DIR__"dong03",
                "west" : __DIR__"dong2"+(random(4)+5),
	]));
        
	set("no_clean_up", 0);
  	setup();
	replace_program(ROOM);
}
