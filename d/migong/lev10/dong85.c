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
		"east" : __DIR__"dong9",
		"west" : __DIR__"dong86",
                	]));
if (random(3)==0)
	set("exits", ([
		"east" : __DIR__"dong9",
		"west" : __DIR__"dong86",
                "down" : "/d/migong/lev11/dong01",
                	]));
         set("objects", ([
              __DIR__"npc/lev"+(random(9)+1) : 1,
             __DIR__"npc/lev"+(random(9)+1) : 1,
                ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
