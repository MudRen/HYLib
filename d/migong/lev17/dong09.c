
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", BLK"��֮����"NOR);
	set("long", BLU @LONG
   һ�������������, �������ƺ��������µ��������������ȥ, �����С��
�������ÿһ��. Խ�����������ˮ��Խ��
LONG NOR);


	set("exits", ([
		"east" : __DIR__"dong0"+(random(9)+1),
		"south" : __DIR__"dong0"+(random(9)+1),
                "west" : __DIR__"dong10",
                "north" : __DIR__"dong0"+(random(9)+1),
	]));
if (random(2)==0)
	set("exits", ([
                "west" : __DIR__"dong10",
		"east" : __DIR__"dong0"+(random(9)+1),
	]));

         set("objects", ([
              "/d/migong/obj/npc1" : random(2),
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
