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
		"west" : __DIR__"dong8"+(random(4)+1),
		"north" : __DIR__"dong8"+(random(4)+1),
		"east" : __DIR__"dong84",
		"south" : __DIR__"dong8"+(random(4)+1),
	]));
if (random(2)==0)
	set("exits", ([
		"south" : __DIR__"dong84",
		"north" : __DIR__"dong8"+(random(4)+1),
	]));
if (random(3)==0)
	set("exits", ([
		"west" : __DIR__"dong84",
		"east" : __DIR__"dong79",
	]));
        set("objects", ([
              __DIR__"npc/lev9" : 2,
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
