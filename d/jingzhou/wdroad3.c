// wdroad3.c
// netkill /98/8/17/

inherit ROOM;

void create()
{
	set("short", "��ʯ���");
	set("long", @LONG
	������һ����ʯ����ϣ����ܾ����ĵġ�
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"south" : __DIR__"wdroad2",
		"north" : __DIR__"wdroad4",
	]));

	setup();
	replace_program(ROOM);
}

