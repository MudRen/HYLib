
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIM"������Թ�"NOR);
	set("long", RED @LONG
�����ǻ�����Թ�,�ƺ����������ѵĵط���Ȼ����
�ϵ�����һ�ѶѵĹǺ���Ǭ����Ѫ���������˾�������
�Ե�ʮ�ֵĹ��졣
LONG NOR);
set("magicroom",1);set("outdoors","migong");
set("magicset",1);

	set("exits", ([
		"southeast" : __DIR__"dong1"+(random(7)+3),
                "northwest" : __DIR__"dong17",
		"eastnorth" : __DIR__"dong1"+(random(7)+1),
                "westsouth" : __DIR__"dong51",
	]));
if (random(3)==0)
	set("exits", ([
		"eastwest" : __DIR__"dong1"+(random(5)+4),
                "southwest" : __DIR__"dong1"+(random(5)+3),
"south" : __DIR__"dong51",
	]));
if (random(3)==1)
	set("exits", ([
		"south" : __DIR__"dong1"+(random(5)+3),
                "north" : __DIR__"dong1"+(random(5)+3),
"north" : __DIR__"dong51",
	]));

	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
