
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
		"south" : __DIR__"dong61",
		"east" : __DIR__"dong5"+(random(9)+1),
		"west" : __DIR__"dong5"+(random(9)+1),
		"north" : __DIR__"dong56",
	]));
if (random(3)==0)
	set("exits", ([
		"south" : __DIR__"dong61",
		"north" : __DIR__"dong57",
	]));
if (random(3)==0)
	set("exits", ([
		"east" : __DIR__"dong59",
		"west" : __DIR__"dong58",
	]));

if (random(3)==0)
	set("exits", ([
		"west" : __DIR__"dong5"+(random(5)+3),
		"east" : __DIR__"dong5"+(random(5)+3),
		"south" : __DIR__"dong5"+(random(5)+3),
		"north" : __DIR__"dong61",
	]));
        set("objects", ([
              __DIR__"npc/lev8" : 5,
              "/clone/box/gboxm" : 1,
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

