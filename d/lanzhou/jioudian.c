// Room: /lanzhou/jioudian.c
// xws 1998/10/14 

inherit ROOM;

void create()
{
	set("short", "迎风酒店");
	set("long", @LONG
    方圆数百里内提起兰州迎风酒楼可以说是无人不知，无人不晓。连西域的人
对迎风酒楼的花雕酒赞不绝口。你站在酒店内，百年陈酿独特的香味，向你阵阵
飘来。
LONG
	);

	set("exits", ([
		"north" : __DIR__"xiaojisi",
		]));

	set("objects", ([
		__DIR__"npc/xiaoer3" : 1,
	]));

	setup();
	replace_program(ROOM);
}

