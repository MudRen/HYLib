
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
		"west" : __DIR__"dong14",
		"east" : __DIR__"dong51",
	]));
if (random(3)==0)
	set("exits", ([
		"south" : __DIR__"dong1"+(random(3)+4),
		"north" : __DIR__"dong1"+(random(3)+4),
		"west" : __DIR__"dong17",
                "east" : __DIR__"dong52",
	]));
if (random(3)==0)
	set("exits", ([
		"south" : __DIR__"dong52",
		"west" : __DIR__"dong18",
	]));

        set("objects", ([
              __DIR__"npc/lev2" : 2,
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

