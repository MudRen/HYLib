#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
		set("short", RED"���Ҷ�"NOR);
	set("long", RED @LONG
    �����ҽ�����ɢ�������������˴�����������һЩǰ��
δ���ľ޴������������߶��š� 
LONG NOR);
	set("exits", ([
		"east" : __DIR__"dong61",
		"west" : __DIR__"dong03",
		"north" : __DIR__"dong1"+(random(9)+1),
		"south" : __DIR__"dong2"+(random(9)+1),
                	]));
 set("objects", ([
             "/d/migong/obj/npc1" : random(2),
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
