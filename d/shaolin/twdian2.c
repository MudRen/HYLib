// Room: /d/shaolin/twdian2.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "西侧殿");
	set("long", @LONG
这里是西侧殿。房间四周悬挂着达摩祖师、观音大士的画
像，以及一些寺内元老的字画。地下散乱地放着许多蒲团，木
鱼等。看来此处是本派弟子打坐修行之所。几位中年和尚手持
数珠，正在喃喃念经。
LONG );
	set("exits", ([
		"east" : __DIR__"twdian",
	]));
	set("sleep_room", "1");
	set("no_fight", "1");
	set("no_npc", "1");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

