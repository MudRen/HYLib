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
		"southdown" : __DIR__"dong99",
		"northup" : __DIR__"dong9"+(random(4)+6),
	]));
if (random(3)==0)
	set("exits", ([
		"west" : __DIR__"dong9"+(random(4)+6),
            	"east" : __DIR__"dong9"+(random(4)+6),
		"south" : __DIR__"dong9"+(random(2)+8),
		"north" : __DIR__"dong9"+(random(4)+6),
	]));
if (random(3)==0)
	set("exits", ([
		"westup" : __DIR__"dong9"+(random(4)+6),
            	"eastdown" : __DIR__"dong99",
	]));

	set("no_clean_up", 0);
        set("objects", ([
     __DIR__"npc/lev8" : 2,
     __DIR__"npc/lev9" : 5,
     __DIR__"npc/lev7" : 2,
         ]));
	setup();
	replace_program(ROOM);
}
