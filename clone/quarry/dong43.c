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
		"north" : __DIR__"dong04",
		"south" : __DIR__"dong44",
                	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}