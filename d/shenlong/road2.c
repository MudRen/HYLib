
inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
����һ����խ��ɽ��,���ű���һ��ɽ����ȥ.ת���˼���ɽ��,̧ͷ
ң���嶥���ż���������.
LONG );
	set("exits", ([
		"north" : __DIR__"damen",
		"south" : __DIR__"road",
	]));
	set("objects", ([
		"/d/city2/npc/dizi": random(4),
		__DIR__"npc/old": random(3),
	]) );
	setup();
	replace_program(ROOM);
}

