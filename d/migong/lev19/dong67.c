#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", RED"��֮��"NOR);
	set("long",HIW @LONG
   ��������һ��������ɽ�������һƬ�տ�������ֻ�б�������պ���
���еİ��ƾ����������������ĺ���������˷����������������Щ���䡣
�������������磿��������в��ɵ���������  
LONG NOR);

set("magicroom",1);set("outdoors","migong");
set("magicset",1);

	set("exits", ([
		"westnorth" : __DIR__"dong68",
		"eastsouth" : __DIR__"dong6"+(random(7)+2),
		"south" : __DIR__"dong6"+(random(7)+2),
		"north" : __DIR__"dong6"+(random(7)+2),
	]));
if (random(3)==0)
	set("exits", ([
		"south" : __DIR__"dong68",
		"north" : __DIR__"dong52",
	]));

if (random(2)==0)
	set("exits", ([
		"west" : __DIR__"dong6"+(random(4)+5),
		"east" : __DIR__"dong6"+(random(7)+2),
		"south" : __DIR__"dong6"+(random(4)+5),
		"north" : __DIR__"dong6"+(random(7)+2),
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
