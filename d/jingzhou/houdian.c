// Room: houdian
// congw 980830 

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
����ĺ��ѷ����㡢������ǽ�ϵ�ᣲ����������µġ�

LONG
	);

	set("exits", ([
		"northdown" : __DIR__"houmen",
		"east" : __DIR__"guanmiao",
		]));

	setup();
	replace_program(ROOM);
}

