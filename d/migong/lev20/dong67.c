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
		"westnorth" : __DIR__"dong68",
		"eastsouth" : __DIR__"dong6"+(random(7)+2),
		"southeast" : __DIR__"dong6"+(random(7)+2),
		"northwest" : __DIR__"dong6"+(random(7)+2),
	]));
if (random(3)==0)
	set("exits", ([
		"southup" : __DIR__"dong68",
		"northdown" : __DIR__"dong52",
	]));

if (random(2)==0)
	set("exits", ([
		"west" : __DIR__"dong6"+(random(4)+5),
		"east" : __DIR__"dong6"+(random(7)+2),
		"south" : __DIR__"dong6"+(random(4)+5),
		"north" : __DIR__"dong6"+(random(7)+2),
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
