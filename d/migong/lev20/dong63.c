
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
		"west" : __DIR__"dong5"+(random(5)+3),
		"east" : __DIR__"dong5"+(random(4)+1),
		"north" : __DIR__"dong64",
		"south" : __DIR__"dong60",
	]));
if (random(2)==0)
	set("exits", ([
		"west" : __DIR__"dong6"+(random(3)+2),
		"east" : __DIR__"dong6"+(random(4)+1),
		"south" : __DIR__"dong6"+(random(3)+2),
		"north" : __DIR__"dong6"+(random(4)+1),
	]));
        set("objects", ([
              __DIR__"npc/player" : 1,
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

