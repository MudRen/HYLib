#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", GRN"ԭʼɭ��"NOR);
	set("long", GRN @LONG
����һ��������ʯ������Χ���Ǽ�Ӳ��ʯ��,�����н���
�ƺ�����һֱ����ȥ�� 
LONG NOR);
	set("exits", ([
		"north" : __DIR__"dong99",
		"south" : __DIR__"dong10",
                "out" : "/d/pingan/nan3"
                	]));
	set("no_npc",1);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
