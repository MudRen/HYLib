
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", BLK"��֮����"NOR);
	set("long", BLK @LONG
   һ�������������, �������ƺ��������µ��������������ȥ, ��
����С��Խ�����������ˮ��Խ��, �����������Ҳ��������ȫ����
ס��. ��������Ѿ��޷�����ؿ������ܵ�״����, ֻ֪����Ľ��Ѿ�
���������������.
LONG NOR);
set("magicroom",1);set("outdoors","migong");
set("magicset",1);

	set("exits", ([
		"south" : __DIR__"dong1"+(random(7)+4),
                "north" : __DIR__"dong1"+(random(7)+1),
		"east" : __DIR__"dong1"+(random(7)+1),
                "west" : __DIR__"dong17",
	]));
if (random(3)==0)
	set("exits", ([
		"eastwest" : __DIR__"dong1"+(random(5)+4),
                "southwest" : __DIR__"dong1"+(random(5)+3),
	]));
if (random(4)==1)
	set("exits", ([
		"south" : __DIR__"dong1"+(random(5)+3),
                "north" : __DIR__"dong1"+(random(5)+4),
	]));

	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
