
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
		"east" : __DIR__"dong0"+(random(5)+4),
		"south" : __DIR__"dong08",
                "west" : __DIR__"dong0"+(random(5)+4),
                "north" : __DIR__"dong04",
	]));
if (random(2)==0)
	set("exits", ([
		"eastsouth" : __DIR__"dong0"+(random(5)+4),
		"southwest" : __DIR__"dong08",
                "westnorth" : __DIR__"dong0"+(random(5)+4),
                "northeast" : __DIR__"dong04",
	]));

         set("objects", ([
              __DIR__"npc/lev1" : random(2),
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
