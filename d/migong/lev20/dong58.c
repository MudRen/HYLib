
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
		"east" : __DIR__"dong59",
		"west" : __DIR__"dong5"+(random(5)+4),
		"south" : __DIR__"dong5"+(random(5)+4),
		"north" : __DIR__"dong5"+(random(5)+4),
	]));
if (random(2)==0)
	set("exits", ([
		"west" : __DIR__"dong5"+(random(5)+3),
		"east" : __DIR__"dong5"+(random(5)+4),
		"north" : __DIR__"dong59",
		"south" : __DIR__"dong5"+(random(5)+1),
	]));
        set("objects", ([
              __DIR__"npc/lev6" : 6,
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

