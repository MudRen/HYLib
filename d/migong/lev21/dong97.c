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
		"westdown" : __DIR__"dong98",
            	"eastup" : __DIR__"dong9"+(random(4)+3),
	]));
if (random(2)==0)
	set("exits", ([
		"west" : __DIR__"dong9"+(random(4)+5),
            	"east" : __DIR__"dong9"+(random(4)+5),
		"south" : __DIR__"dong9"+(random(4)+5),
		"north" : __DIR__"dong9"+(random(4)+5),
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
