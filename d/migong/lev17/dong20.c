
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
                "west" : __DIR__"dong1"+(random(6)+3),
		"east" : __DIR__"dong1"+(random(6)+3),
		"south" : __DIR__"dong1"+(random(8)+1),
                "north" : __DIR__"dong21",
	]));
if (random(3)==0)
	set("exits", ([
		"east" : __DIR__"dong1"+(random(8)+1),
                "west" : __DIR__"dong21",
	]));
if (random(4)==1)
	set("exits", ([
		"south" : __DIR__"dong2"+(random(8)+1),
                "north" : __DIR__"dong1"+(random(9)+1),
	]));
         set("objects", ([
"/clone/box/gboxm" : random(2),
              __DIR__"npc/lev3" : random(4),
              __DIR__"npc/lev4" : random(4),
         ]));

	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
