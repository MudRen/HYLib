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
		"north" : __DIR__"dong67",
		"south" : __DIR__"dong6",
		"west" : __DIR__"dong3"+(random(9)+1),
		"east" : __DIR__"dong4"+(random(9)+1),
                	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
