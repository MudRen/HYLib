// wdroad4.c
//netkill /98/8/17/
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
		//"east" : "/d/xiaoyao/shulin3",
		"south" : __DIR__"wdroad3",
		"north" : __DIR__"wdroad5",
	]));

	setup();
	replace_program(ROOM);
}

