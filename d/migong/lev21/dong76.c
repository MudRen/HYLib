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
		"west" : __DIR__"dong7"+(random(4)+4),
		"east" : __DIR__"dong7"+(random(4)+5),
		"south" : __DIR__"dong7"+(random(4)+4),
		"north" : __DIR__"dong7"+(random(4)+4),
	]));
if (random(2)==0)
	set("exits", ([
		"south" : __DIR__"dong7"+(random(4)+5),
		"north" : __DIR__"dong7"+(random(4)+4),
	]));
if (random(3)==0)
	set("exits", ([
		"east" : __DIR__"dong77",
		"west" : __DIR__"dong7"+(random(4)+5),
	]));
         set("objects", ([
              __DIR__"npc/lev8" : 6,
              __DIR__"npc/player" : 3,
              "/clone/box/gboxm" : random(3),
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
