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
		"south" : __DIR__"dong19",
		"west" : __DIR__"dong6"+(random(7)+1),
		"north" : __DIR__"dong5"+(random(7)+1),
		"east" : __DIR__"dong72",
	]));
if (random(3)==0)
	set("exits", ([
		"east" : __DIR__"dong19",
		"west" : __DIR__"dong72",
		"south" : __DIR__"dong5"+(random(7)+1),
		"north" : __DIR__"dong6"+(random(7)+1),
	]));
if (random(3)==0)
	set("exits", ([
		"west" : __DIR__"dong7"+(random(3)+2),
		"east" : __DIR__"dong19",
	]));
if (random(3)==0)
	set("exits", ([
		"south" : __DIR__"dong7"+(random(3)+2),
		"north" : __DIR__"dong19",
	]));
         set("objects", ([
              __DIR__"npc/lev3" : 3,
              __DIR__"npc/lev4" : 3,
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
