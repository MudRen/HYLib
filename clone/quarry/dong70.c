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
		"east" : __DIR__"dong69",
		"west" : __DIR__"dong02",
"out" : "/d/pingan/nan3"
                	]));
 set("objects", ([
              __DIR__"npc/"+(random(28)+11) : 1,
             __DIR__"npc/"+(random(28)+11) : 1,
                ]));

	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
