#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{	
       set("short", YEL"�Ҷ����"NOR);
	set("long", YEL @LONG
    ��Χ���ǻƺ�ɫ����ʯ���о����Ѿ��ڵ��º���ĵط��ˡ� 
LONG NOR);
	set("exits", ([
		"east" : __DIR__"dong87",
		"west" : __DIR__"dong12",
		"north" : __DIR__"dong1"+(random(9)+1),
		"south" : __DIR__"dong2"+(random(9)+1),
                	]));
if (random(3)==0)
	set("exits", ([
		"east" : __DIR__"dong12",
		"west" : __DIR__"dong87",
                "down" : "/d/migong/lev12/dong02",
                	]));
         set("objects", ([
              __DIR__"npc/lev"+(random(9)+1) : 1,
             __DIR__"npc/lev"+(random(9)+1) : 1,
                ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
