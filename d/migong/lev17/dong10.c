
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
		"east" : __DIR__"dong0"+(random(6)+2),
		"south" : __DIR__"dong0"+(random(6)+3),
                "west" : __DIR__"dong0"+(random(6)+3),
                "north" : __DIR__"dong1"+(random(3)+1),
	]));
         set("objects", ([
              __DIR__"npc/lev2" : random(2),
              "/clone/box/gboxm" : 1,
              __DIR__"npc/lev2" : random(2),
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
