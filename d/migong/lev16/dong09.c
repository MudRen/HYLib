
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
		"east" : __DIR__"dong0"+(random(9)+1),
		"south" : __DIR__"dong0"+(random(9)+1),
                "west" : __DIR__"dong10",
                "north" : __DIR__"dong0"+(random(9)+1),
	]));
if (random(2)==0)
	set("exits", ([
                "up" : __DIR__"dong10",
	]));

         set("objects", ([
              "/d/migong/obj/npc1" : random(2),
              "/d/migong/lev20/npc/leva" : random(2),
              "/d/migong/lev20/npc/levb" : random(2),
              "/d/migong/lev20/npc/levc" : random(2),   
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
