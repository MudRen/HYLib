
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
        set("outdoors", "migong");
set("magicroom",1);set("outdoors","migong");
set("magicset",1);
	set("exits", ([
                "west" : __DIR__"dong3"+(random(4)+4),
		"east" : __DIR__"dong3"+(random(4)+4),
		"south" : __DIR__"dong37",
                "north" : __DIR__"dong35",
	]));
if (random(2)==0)
	set("exits", ([
                "west" : __DIR__"dong3"+(random(4)+4),
		"east" : __DIR__"dong3"+(random(4)+4),
	]));
if (random(2)==0)
	set("exits", ([
		"south" : __DIR__"dong3"+(random(4)+4),
                "north" : __DIR__"dong3"+(random(4)+4),
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

