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
		"east" : __DIR__"dong8",
		"west" : __DIR__"dong78",
                	]));
         set("objects", ([
              __DIR__"npc/"+(random(38)+1) : 1,
             __DIR__"npc/"+(random(38)+1) : 1,
                ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
