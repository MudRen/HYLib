// /u/dubei/gumu/hxl1
// by dubei
#include <ansi.h>
inherit ROOM;
void create()

{
set("short", "����С·");

	set("long", @LONG
 
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
	    "down" : __DIR__"banshan2",
]));
	set("no_clean_up", 0);

	setup();
}

void init()
{	
	add_action("do_down", "pa");
}

int do_down(string arg)
{
	object me = this_player();
	message_vision(HIR "$N�������ϣ����������һ�����ﵽ�˹ȵס�\n" NOR, me);
	me->move(__DIR__"gudi");
	return 1;
}
