
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
		set("short", WHT"����ʯ��"NOR);
	set("long", WHT @LONG
 �������Ǽ�������ʯ�����ܲ�ͣ����ˮ����¡� 
LONG NOR);
	set("exits", ([
		"east" : __DIR__"dong"+(random(17)+4),
		"south" : __DIR__"dong"+(random(12)+4),
                "west" : __DIR__"dong"+(random(7)+4),
                "north" : __DIR__"dong"+(random(2)+4),
	]));
if (random(3)==0)
	set("exits", ([
		"east" : __DIR__"dong"+(random(20)+21),
                "west" : __DIR__"dong"+(random(10)+31),
	]));

if (random(3)==0)
	set("exits", ([
		"south" : __DIR__"dong"+(random(15)+41),
                "north" : __DIR__"dong"+(random(5)+51),
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
