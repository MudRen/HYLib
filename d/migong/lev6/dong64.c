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
		"east" : __DIR__"dong63",
		"west" : __DIR__"dong15",
                	]));
if (random(3)==0)
	set("exits", ([
		"east" : __DIR__"dong63",
		"west" : __DIR__"dong15",
                "down" : "/d/migong/lev7/dong01",
                	]));
       set("objects", ([
              __DIR__"npc/lev"+(random(9)+1) : 1,
             __DIR__"npc/lev"+(random(9)+1) : 1,
"/clone/box/gbox" : random(2),
                ]));          
	set("no_clean_up", 0);        
	setup();
	replace_program(ROOM);
}
