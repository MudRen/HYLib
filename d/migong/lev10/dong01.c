
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", YEL"�Ҷ�"NOR);
	set("long", YEL @LONG
    ��Χ���ǻƺ�ɫ����ʯ���о����Ѿ��ڵ��º���ĵط��ˡ� 
LONG NOR);
	set("exits", ([
		"east" : __DIR__"dong"+(random(20)+1),
		"south" : __DIR__"dong"+(random(15)+1),
                "west" : __DIR__"dong"+(random(10)+1),
                "north" : __DIR__"dong"+(random(5)+1),
	]));
if (random(3)==0)
	set("exits", ([
		"east" : __DIR__"dong"+(random(20)+21),
                "west" : __DIR__"dong"+(random(10)+31),
	]));

if (random(3)==0)
	set("exits", ([
		"south" : __DIR__"dong"+(random(15)+41),
                "north" : __DIR__"dong"+(random(5)+51),
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
