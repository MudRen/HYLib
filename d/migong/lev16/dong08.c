
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", BLU"���׹���"NOR);
	set("long", BLU @LONG
����һ�����׹�������ͣ����һ��һ��ĺ���������ͷ�ϴ���....
������·�ܶ࣬��ͨ�˴��е����ֲ���ȫ�ĸо���
LONG NOR);


	set("exits", ([
		"east" : __DIR__"dong09",
		"south" : __DIR__"dong0"+(random(9)+1),
                "west" : __DIR__"dong0"+(random(9)+1),
                "north" : __DIR__"dong0"+(random(8)+1),
	]));
if (random(2)==0)
	set("exits", ([
		"south" : __DIR__"dong0"+(random(9)+1),
                "north" : __DIR__"dong09",
	]));
         set("objects", ([
              "/d/migong/obj/npc2" : random(2),
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
