
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
                "west" : __DIR__"dong3"+(random(5)+4),
		"east" : __DIR__"dong3"+(random(4)+5),
		"south" : __DIR__"dong3"+(random(4)+5),
                "north" : __DIR__"dong3"+(random(5)+4),
	]));
if (random(2)==0)
	set("exits", ([
		"east" : __DIR__"dong3"+(random(4)+5),
                "west" : __DIR__"dong3"+(random(4)+5),
	]));
if (random(2)==0)
	set("exits", ([
		"south" : __DIR__"dong3"+(random(4)+5),
                "north" : __DIR__"dong3"+(random(4)+5),
	]));

         set("objects", ([
              __DIR__"npc/lev5" : random(9),
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

