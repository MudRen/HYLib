
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
		"north" : __DIR__"dong62",
		"east" : __DIR__"dong5"+(random(4)+1),
		"south" : __DIR__"dong5"+(random(5)+3),
		"west" : __DIR__"dong6"+(random(4)+1),
	]));
if (random(2)==0)
	set("exits", ([
		"east" : __DIR__"dong6"+(random(4)+1),
		"west" : __DIR__"dong5"+(random(4)+1),
		"south" : __DIR__"dong6"+(random(4)+1),
		"north" : __DIR__"dong6"+(random(4)+1),
	]));
        set("objects", ([
              __DIR__"npc/lev4" : 3,
              __DIR__"npc/player" : 1,
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

