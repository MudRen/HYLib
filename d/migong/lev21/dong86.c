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
		"west" : __DIR__"dong8"+(random(4)+3),
            	"east" : __DIR__"dong8"+(random(4)+3),
		"north" : __DIR__"dong8"+(random(4)+3),
		"south" : __DIR__"dong87",
	]));
if (random(3)==0)
	set("exits", ([
		"southdown" : __DIR__"dong8"+(random(3)+5),
		"northdown" : __DIR__"dong8"+(random(4)+4),
	]));
if (random(3)==0)
	set("exits", ([
		"westdown" : __DIR__"dong8"+(random(3)+1),
		"eastdown" : __DIR__"dong87",
	]));
        set("objects", ([
              __DIR__"npc/lev9" : 2,
              __DIR__"npc/player" : 1,
              "/clone/box/gboxm" : 1,
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
