
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
		"south" : __DIR__"dong1"+(random(8)+1),
                "north" : __DIR__"dong20",
		"east" : __DIR__"dong1"+(random(8)+1),
                "west" : __DIR__"dong1"+(random(8)+1),
	]));
if (random(3)==0)
	set("exits", ([
		"west" : __DIR__"dong20",
		"east" : __DIR__"dong1"+(random(8)+1),
                "west" : __DIR__"dong1"+(random(8)+1),
	]));
if (random(3)==1)
	set("exits", ([
		"south" : __DIR__"dong20",
                "north" : __DIR__"dong1"+(random(9)+1),
	]));
         set("objects", ([
              __DIR__"npc/lev3" : random(3),
              "/clone/box/gboxm" : random(2),
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
