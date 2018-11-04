
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
		"west" : __DIR__"dong58",
		"east" : __DIR__"dong5"+(random(5)+4),
		"south" : __DIR__"dong56",
		"north" : __DIR__"dong5"+(random(5)+4),
	]));
if (random(2)==0)
	set("exits", ([
		"west" : __DIR__"dong5"+(random(5)+3),
		"east" : __DIR__"dong58",
		"south" : __DIR__"dong5"+(random(5)+3),
		"north" : __DIR__"dong5"+(random(5)+4),
	]));
if (random(3)==0)
	set("exits", ([
		"east" : __DIR__"dong58",
		"west" : __DIR__"dong56",
	]));

         set("objects", ([
              __DIR__"npc/lev5" : 3,
              "/clone/box/gboxm" : random(2),
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

