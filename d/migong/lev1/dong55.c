#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", CYN"ʯ�����"NOR);
	set("long", CYN @LONG
����һ��������ʯ������Χ���Ǽ�Ӳ��ʯ�ڡ� 
LONG NOR);
	set("exits", ([
		"east" : __DIR__"dong03",
		"west" : __DIR__"dong56",
                	]));
if (random(3)==0)
	set("exits", ([
		"east" : __DIR__"dong03",
		"west" : __DIR__"dong56",
                "down" : "/d/migong/lev2/dong01",
                	]));

	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
