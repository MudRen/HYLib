
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", BLK"��֮����"NOR);
	set("long", BLK @LONG
   һ�������������, �������ƺ��������µ��������������ȥ, �����С��
�������ÿһ��. Խ�����������ˮ��Խ�
LONG NOR);
set("magicroom",1);set("outdoors","migong");
set("magicset",1);
	set("exits", ([
		"east" : __DIR__"dong0"+(random(4)+3),
                "west" : __DIR__"dong0"+(random(4)+3),
		"south" : __DIR__"dong0"+(random(4)+3),
                "north" : __DIR__"dong0"+(random(4)+3),
	]));
if (random(3)==0)
	set("exits", ([
		"westeast" : __DIR__"dong0"+(random(4)+3),
		"east" : __DIR__"dong06",
		"eastsouth" : __DIR__"dong0"+(random(4)+3),
                "northwest" : __DIR__"dong0"+(random(4)+3),
                "southnorth" : __DIR__"dong0"+(random(4)+3),
	]));
         set("objects", ([
              __DIR__"npc/lev1" : random(3),
              __DIR__"npc/lev2" : random(2),
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
