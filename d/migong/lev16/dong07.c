
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
		"east" : __DIR__"dong0"+(random(8)+1),
		"south" : __DIR__"dong06",
                "west" : __DIR__"dong0"+(random(8)+1),
                "north" : __DIR__"dong08",
	]));
if (random(2)==0)
	set("exits", ([
		"eastsouth" : __DIR__"dong0"+(random(8)+1),
		"southwest" : __DIR__"dong06",
                "westnorth" : __DIR__"dong0"+(random(8)+1),
                "northeast" : __DIR__"dong08",
	]));

         set("objects", ([
              "/d/migong/obj/npc1" : random(2),
              "/d/migong/lev19/npc/leva" : random(2),
              "/d/migong/lev19/npc/levb" : random(2),
              "/d/migong/lev19/npc/levc" : random(2),   
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
