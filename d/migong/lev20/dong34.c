
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"ǰ���Ĺ���"NOR);
	set("long", HIY @LONG
  ������һ���ѷ�������ļ�̳.������Ȼ�м�����ж�,
ĳ�����ƺ���������������һ�����ܵļ���.��̳������һ
�������һ���ȼ������
LONG NOR);
set("magicroom",1);set("outdoors","migong");
set("magicset",1);
        set("outdoors", "migong");
	set("exits", ([
		"east" : __DIR__"dong12",
                "south" : __DIR__"dong12",
		"north" : __DIR__"dong35",
		"west" : __DIR__"dong11",
	]));
if (random(2)==0)
	set("exits", ([
		"south" : __DIR__"dong12",
                "north" : __DIR__"dong35",
	]));
if (random(2)==0)
	set("exits", ([
		"west" : __DIR__"dong11",
                "east" : __DIR__"dong35",
	]));

	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

