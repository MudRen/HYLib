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
		"west" : __DIR__"dong6"+(random(5)+2),
		"east" : __DIR__"dong6"+(random(5)+2),
		"down" : __DIR__"dong67",
		"up" : __DIR__"dong63",
	]));
if (random(2)==0)
	set("exits", ([
		"west" : __DIR__"dong67",
		"east" : __DIR__"dong6"+(random(5)+2),
		"south" : __DIR__"dong6"+(random(5)+2),
		"north" : __DIR__"dong6"+(random(5)+2),
	]));
if (random(3)==0)
	set("exits", ([
		"south" : __DIR__"dong67",
		"north" : __DIR__"dong63",
	]));
if (random(3)==0)
	set("exits", ([
		"east" : __DIR__"dong63",
		"west" : __DIR__"dong67",
	]));

        set("objects", ([
              __DIR__"npc/lev8" : 5,
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
