#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
		set("short", BLU"ɽ�����"NOR);
	set("long", BLU @LONG
 ��Խ��Խ���Χ��ǽ���ƺ���Щ�����ˡ� 
LONG NOR);
	set("exits", ([
		"north" : __DIR__"dong03",
		"south" : __DIR__"dong60",
                	]));
if (random(3)==0)
	set("exits", ([
		"east" : __DIR__"dong03",
		"west" : __DIR__"dong60",
                "down" : "/d/migong/lev5/dong03",
                	]));	
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
