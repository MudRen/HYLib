#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
		set("short", RED"���Ҷ�����"NOR);
	set("long", RED @LONG
    �����ҽ�����ɢ�������������˴�����������һЩǰ��
δ���ľ޴������������߶��š� 
LONG NOR);
	set("exits", ([
		"south" : __DIR__"dong1",
		"up" : "/d/migong/lev14/dong02",
                	]));
        set("objects", ([
             "/d/migong/obj/npc1" : random(3),             
              "/d/migong/lev17/npc/leva" : random(2),
              "/d/migong/lev17/npc/levb" : random(2),
              "/d/migong/lev17/npc/levc" : random(2),   
              "/d/migong/lev18/npc/leva" : random(2),
              "/d/migong/lev18/npc/levb" : random(2),
              "/d/migong/lev18/npc/levc" : random(2), 
              "/d/migong/lev19/npc/leva" : random(2),
              "/d/migong/lev19/npc/levb" : random(2),
              "/d/migong/lev19/npc/levc" : random(2), 

                ]));
                set("no_clean_up", 0);
set("no_npc",1);
	setup();
	replace_program(ROOM);
}
