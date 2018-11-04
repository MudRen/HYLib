// Room: /d/fuzhou/beidajie.c
// may. 12 1998 Java

inherit ROOM;

void create()
{
	set("short", "北大街");
	set("long", @LONG
街道两侧，榕木参天。福州盛夏苦热，广植榕树以纳凉
爽，别名“榕城”。南面是一个大路口，北上就是屏山。
LONG );
	set("exits", ([
		"south"   : __DIR__"dongjiekou",
		"northup" : __DIR__"pingshan",
	]));
	set("outdoors", "quanzhou");
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

