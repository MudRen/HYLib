#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
		set("short", WHT"����ʯ�����"NOR);
	set("long", WHT @LONG
 �������Ǽ�������ʯ�����ܲ�ͣ����ˮ����¡� 
LONG NOR);
	set("exits", ([
		"north" : __DIR__"dong75",
		"south" : __DIR__"dong7",
                	]));
if (random(3)==0)
	set("exits", ([
		"east" : __DIR__"dong7",
		"west" : __DIR__"dong75",
                "down" : "/d/migong/lev9/dong04",
                	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
