
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
		"east" : __DIR__"dong02",
                "west" : "/d/migong/lev16/dong20",
	]));
set("no_npc",1);
         set("objects", ([
              __DIR__"npc/lev1" : random(3),
         ]));
if (random(2)==0)
	set("exits", ([
		"east" : __DIR__"dong0"+(random(3)+1),
                "west" : "/d/migong/lev16/dong20",
		"south" : __DIR__"dong02",
                "north" : __DIR__"dong0"+(random(3)+1),
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
