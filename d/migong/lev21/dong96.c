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

	set("exits", ([
		"westsouth" : __DIR__"dong97",
            	"eastnorth" : __DIR__"dong9"+(random(4)+3),
		"southdown" : __DIR__"dong9"+(random(4)+3),
		"northup" : __DIR__"dong9"+(random(4)+3),
	]));
if (random(3)==0)
	set("exits", ([
		"south" : __DIR__"dong9"+(random(2)+6),
		"north" : __DIR__"dong9"+(random(2)+6),
	]));

if (random(3)==0)
	set("exits", ([
		"east" : __DIR__"dong9"+(random(4)+3),
            	"west" : __DIR__"dong97",
	]));
        set("objects", ([
     __DIR__"npc/lev8" : 2,
     __DIR__"npc/player" : 2,
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
