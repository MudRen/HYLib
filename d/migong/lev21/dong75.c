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
if (random(3)==0)
	set("exits", ([
		"westdown" : __DIR__"dong76",
		"eastdown" : __DIR__"dong7"+(random(4)+3),
	]));
	set("exits", ([
		"east" : __DIR__"dong76",
		"west" : __DIR__"dong7"+(random(4)+3),
		"south" : __DIR__"dong7"+(random(4)+3),
		"north" : __DIR__"dong7"+(random(4)+3),
	]));
if (random(3)==0)
	set("exits", ([
		"southdown" : __DIR__"dong7"+(random(4)+3),
		"northdown" : __DIR__"dong76",
	]));
         set("objects", ([
              __DIR__"npc/lev5" : 2,
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
