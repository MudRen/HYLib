// Room: /u/qingyun/jyzj/hongmeizhuang.c
// Written by qingyun
// Updated by jpei

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIR"��÷ɽׯ"NOR);
	set("long", @LONG
����һ���Ĵ��ׯ�ӡ�һ�ۿ�ȥ��֪���˼������ǵ��صĸ�����������ɽ
������ô���һ��ɽׯȷʵ�ǳ��ټ�����˵���˼�����Ҳ���������ˣ�����·
��֮��Ҳ��������Ľ��룬���Խ���֮�������
LONG	);
	set("exits", ([
		"north" : __DIR__"dating",
		"east" : __DIR__"shanlu2",
		"westdown" : __DIR__"shanxi",
	]));
	set("objects",([
		__DIR__"npc/guanjia" : 1,
	]));
	set("outdoors", "kunlun");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
