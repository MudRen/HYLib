#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
		set("short", RED"���Ҷ����"NOR);
	set("long", RED @LONG
    �����ҽ�����ɢ�������������˴�����������һЩǰ��
δ���ľ޴������������߶��š� 
LONG NOR);
	set("exits", ([
		"east" : __DIR__"dong37",
		"west" : __DIR__"dong04",
                	]));
if (random(3)==0)
	set("exits", ([
		"east" : __DIR__"dong04",
		"west" : __DIR__"dong37",
                "down" : "/d/migong/lev14/dong01",
                	]));
      set("objects", ([
              __DIR__"npc/lev"+(random(9)+1) : 1,
                           ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
