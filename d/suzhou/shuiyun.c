// Room: /d/suzhou/shuiyun.c

inherit ROOM;

void create()
{
	set("short", "ˮ�Ƽ�");
	set("long", @LONG
������̫���ߵ�������ʿ��һ�ж�ֻ�Ǹ��԰���
LONG);
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
  "east" : "/d/mr/matou",
]));
	setup();
//	replace_program(ROOM);
}