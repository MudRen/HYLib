// Room: houmen
// congw 980830 

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����ĺ��ţ�������һ��Сɽ�¡�
LONG
	);

	set("exits", ([
		"south" : __DIR__"houdian",
		"northup" :__DIR__"xiaoshan",
	]));

	setup();
	replace_program(ROOM);
}

