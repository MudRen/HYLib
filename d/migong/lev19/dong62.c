
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
		"south" : __DIR__"dong63",
		"east" : __DIR__"dong5"+(random(4)+1),
		"south" : __DIR__"dong6"+(random(4)+3),
		"west" : __DIR__"dong6"+(random(4)+1),
	]));
if (random(2)==0)
	set("exits", ([
		"west" : __DIR__"dong5"+(random(4)+1),
		"east" : __DIR__"dong6"+(random(2)+2),
		"south" : __DIR__"dong6"+(random(4)+3),
		"north" : __DIR__"dong6"+(random(4)+1),
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

