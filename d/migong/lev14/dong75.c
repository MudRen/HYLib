#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
		set("short", RED"���Ҷ�"NOR);
	set("long", RED @LONG
    �����ҽ�����ɢ�������������˴�����������һЩǰ��
δ���ľ޴������������߶��š� 
LONG NOR);
	set("exits", ([
		"east" : __DIR__"dong76",
		"south" : __DIR__"dong6"+(random(5)+1),
                "west" : __DIR__"dong5"+(random(2)+5),
                "north" : __DIR__"dong0"+(random(2)+1),
	]));
if (random(6)==1)
	set("exits", ([
		"south" : __DIR__"dong0"+(random(2)+1),
                "north" : __DIR__"dong4"+(random(4)+3),
	]));
if (random(9)==0)
	set("exits", ([
		"east" : __DIR__"dong7"+(random(2)+5),
                "west" : __DIR__"dong5"+(random(2)+5),
	]));
       set("objects", ([
              __DIR__"npc/lev"+(random(9)+1) : 1,
             __DIR__"npc/lev"+(random(9)+1) : 1,
                ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
