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
		"east" : __DIR__"dong0"+(random(2)+2),
		"south" : __DIR__"dong3"+(random(5)+1),
                "west" : __DIR__"dong56",
                "north" : __DIR__"dong2"+(random(5)+1),
	]));
if (random(6)==1)
	set("exits", ([
		"south" : __DIR__"dong0"+(random(2)+2),
                "north" : __DIR__"dong4"+(random(4)+3),
	]));
if (random(9)==0)
	set("exits", ([
		"east" : __DIR__"dong1"+(random(6)+1),
                "west" : __DIR__"dong5"+(random(2)+5),
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
