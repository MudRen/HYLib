#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", GRN"ԭʼɭ��"NOR);
	set("long", GRN @LONG
����һ��ԭʼɭ�֣�ɭ�����������ڣ�ˮ���������������Ǹ��ֶ��
LONG NOR);
	set("exits", ([
		"east" : __DIR__"dong05",
		"south" : __DIR__"dong24",
                	]));
 set("objects", ([
              __DIR__"npc/"+(random(38)+1) : 1,
                            ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
