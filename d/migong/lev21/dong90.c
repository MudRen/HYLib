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
		"westdown" : __DIR__"dong91",
            	"eastup" : __DIR__"dong8"+(random(4)+4),
		"southdown" : __DIR__"dong8"+(random(4)+4),
		"northup" : __DIR__"dong8"+(random(4)+4),
	]));
if (random(3)==0)
	set("exits", ([
		"southup" : __DIR__"dong7"+(random(3)+1),
		"northdown" : __DIR__"dong91",
	]));
if (random(3)==0)
	set("exits", ([
		"westsouth" : __DIR__"dong8"+(random(4)+6),
		"eastnorth" : __DIR__"dong91",
	]));
        set("objects", ([
              __DIR__"npc/lev5" : 3,
              __DIR__"npc/lev4" : 3,
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
