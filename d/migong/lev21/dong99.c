#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIB"����Ķ���"NOR);
	set("long", HIB @LONG
�ⶴѨ����һֱ���굽�ص�ȥ.����ӵصײ�ͣ�ش�
����. һЩ����ֵֹ�ͼ�λ�����������Ѩ,����֮��,
���ϵ��㼣Ҳ���������ҵ�.
LONG NOR);
set("magicroom",1);set("outdoors","migong");
set("magicset",1);
set("no_npc",1);
	set("exits", ([
		"south" : __DIR__"dong100",
		"north" : __DIR__"dong9"+(random(4)+6),
		"east" : __DIR__"dong9"+(random(4)+6),
		"west" : __DIR__"dong9"+(random(4)+6),
	]));

if (random(2)==0)
	set("exits", ([
		"west" : __DIR__"dong9"+(random(4)+6),
            	"east" : __DIR__"dong9"+(random(4)+6),
		"south" : __DIR__"dong9"+(random(4)+6),
		"north" : __DIR__"dong9"+(random(4)+6),
	]));
if (random(2)==0)
	set("exits", ([
		"south" : __DIR__"dong9"+(random(4)+6),
		"north" : __DIR__"dong100",
	]));

	set("no_clean_up", 0);
        set("objects", ([
     __DIR__"npc/lev8" : 5,
     __DIR__"npc/lev6" : 5,
     __DIR__"npc/lev7" : 3,
         ]));
	setup();
	replace_program(ROOM);
}
