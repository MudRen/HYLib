#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
		set("short", YEL"�Ҷ�"NOR);
	set("long", YEL @LONG
    ��Χ���ǻƺ�ɫ����ʯ���о����Ѿ��ڵ��º���ĵط��ˡ� 
LONG NOR);
	set("exits", ([
		"east" : __DIR__"dong7"+(random(6)+1),
		"south" : __DIR__"dong6"+(random(5)+1),
                "west" : __DIR__"dong01",
                "north" : __DIR__"dong88",
	]));
if (random(6)==1)
	set("exits", ([
		"south" : __DIR__"dong6"+(random(4)+3),
                "north" : __DIR__"dong8"+(random(2)+7),
	]));
if (random(9)==0)
	set("exits", ([
		"east" : __DIR__"dong0"+(random(2)+1),
                "west" : __DIR__"dong8"+(random(2)+7),
	]));
        set("objects", ([
              __DIR__"npc/lev"+(random(9)+1) : 2,
             __DIR__"npc/lev"+(random(9)+1) : 2,
                ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
