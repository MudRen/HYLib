
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", BLK"��֮����"NOR);
	set("long", RED @LONG
   һ�������������, �������ƺ��������µ��������������ȥ, 
���������о�Ȼ��һ��Сľ�ݣ��������������Ϣһ��(save)��
��˯��(sleep)��
LONG NOR);

set("magicroom",1);set("outdoors","migong");
set("magicset",1);
set("no_fight",1);
set("sleep_room",1);
	set("exits", ([
		"east" : __DIR__"dong0"+(random(4)+1),
                "west" : __DIR__"dong03",
		"south" : __DIR__"dong0"+(random(3)+1),
                "north" : __DIR__"dong0"+(random(4)+1),
	]));
 set("valid_startroom", "1");
if (random(2)==0)
	set("exits", ([
		"east" : __DIR__"dong0"+(random(4)+1),
                "west" : __DIR__"dong03",
	]));

         set("objects", ([
"/d/migong/lev16/npc/obj/food2" : 1,
"/d/migong/lev16/npc/obj/water1" : 1,
              __DIR__"npc/player" : random(2),
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
