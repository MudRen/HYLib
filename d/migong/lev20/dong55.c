
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", WHT"������Թ�"NOR);
	set("long",HIW @LONG
���������ܸо���һ����ʥ��ׯ�ϵ�����,������͵�
�����ʹ����ط���������͵�����,���ﶫ���ϱ�����ͨ
·,����ÿ��ͨ�����ƺ�����ħ���ϱڡ�
LONG NOR);

set("magicroom",1);set("outdoors","migong");
set("magicset",1);

	set("exits", ([
		"west" : __DIR__"dong5"+(random(6)+1),
		"east" : __DIR__"dong5"+(random(6)+1),
		"southup" : __DIR__"dong56",
		"northdown" : __DIR__"dong5"+(random(5)+1),
	]));
if (random(3)==0)
	set("exits", ([
		"north" : __DIR__"dong53",
		"south" : __DIR__"dong56",
	]));
if (random(3)==0)
	set("exits", ([
		"east" : __DIR__"dong56",
		"west" : __DIR__"dong54",
	]));

if (random(4)==0)
	set("exits", ([
		"west" : __DIR__"dong5"+(random(4)+3),
		"east" : __DIR__"dong5"+(random(5)+1),
		"south" : __DIR__"dong5"+(random(4)+3),
		"north" : __DIR__"dong5"+(random(5)+1),
	]));
        set("objects", ([
              __DIR__"npc/lev7" : 1,
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

