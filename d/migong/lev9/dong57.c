#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
		set("short", WHT"����ʯ��"NOR);
	set("long", WHT @LONG
 �������Ǽ�������ʯ�����ܲ�ͣ����ˮ����¡� 
LONG NOR);
	set("exits", ([
		"east" : __DIR__"dong3"+(random(4)+5),
		"south" : __DIR__"dong4"+(random(4)+5),
                "west" : __DIR__"dong58",
                "north" : __DIR__"dong16",
	]));
if (random(6)==1)
	set("exits", ([
		"south" : __DIR__"dong3"+(random(4)+3),
                "north" : __DIR__"dong5"+(random(2)+7),
	]));
if (random(9)==0)
	set("exits", ([
		"east" : __DIR__"dong1"+(random(2)+5),
                "west" : __DIR__"dong4"+(random(4)+5),
	]));
        set("objects", ([
              __DIR__"npc/lev"+(random(9)+1) : 2,
             __DIR__"npc/lev"+(random(9)+1) : 2,
              "/clone/box/gbox" : random(2),
                ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
