// Room: /u/qingyun/jyzj/xuedi1.c
// Written by qingyun
// Updated by jpei

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", HIW"ѩ��"NOR);
	set("long", @LONG
����ɽ����Ƨ��������ɽ�Ͼ��������ѩ������ĵ��ϰ�ѩ����������ֱ
�����˫Ŀ��ѩ����һ�н�ӡͨ�򱱱ߣ������Ǳ�Ӧ������ɽ·�ġ�
LONG	);
	set("exits", ([
		"north" : __DIR__"shanlu1",
		"southwest" : __DIR__"xuedi",
	]));
	set("outdoors", "kunlun");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
