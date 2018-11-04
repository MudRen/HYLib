
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", BLU"���׹�������"NOR);
	set("long", BLU @LONG
����һ�����׹�������ͣ����һ��һ��ĺ���������ͷ�ϴ���....
������·�ܶ࣬��ͨ�˴��е����ֲ���ȫ�ĸо���
LONG NOR);


	set("exits", ([
		"east" : __DIR__"dong0"+(random(6)+2),
		"south" : __DIR__"dong0"+(random(6)+3),
                "west" : __DIR__"dong0"+(random(6)+3),
                "north" : __DIR__"dong0"+(random(6)+3),
                "up" : __DIR__"dong11",
	]));
         set("objects", ([
              "/d/migong/obj/npc1" : random(2),
              "/d/migong/obj/npc2" : random(2),
              "/d/migong/lev21/npc/leva" : random(2),
              "/d/migong/lev21/npc/levb" : random(2),
              "/d/migong/lev21/npc/levc" : random(2),   
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
