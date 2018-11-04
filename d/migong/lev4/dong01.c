
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", BLU"ɽ��"NOR);
	set("long", BLU @LONG
 ��Խ��Խ���Χ��ǽ���ƺ���Щ�����ˡ� 
LONG NOR);
	set("exits", ([
		"south" : __DIR__"dong"+(random(15)+1),
                "north" : __DIR__"dong"+(random(5)+1),
                "west" : __DIR__"dong"+(random(10)+1),
		"east" : __DIR__"dong"+(random(20)+1),
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
