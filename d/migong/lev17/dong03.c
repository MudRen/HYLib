
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
		"south" : __DIR__"dong0"+(random(5)+1),
                "north" : __DIR__"dong04",
	]));
         set("objects", ([
              __DIR__"npc/lev2" : random(2),
         ]));
if (random(2)==0)
	set("exits", ([
		"east" : __DIR__"dong0"+(random(4)+1),
                "west" : __DIR__"dong0"+(random(4)+1),
	 "south" : __DIR__"dong04",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
