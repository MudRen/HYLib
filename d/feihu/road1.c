// ѩ·
// by steel 

inherit ROOM;

void create()
{
	set("short", "ѩԭ");
	set("long", @LONG
	�����Ǳ�����һƬѩԭ,��ѩ���겻��,������ȥ,��ãã��һƬ,
һ����ӰҲ������.    
LONG
	);
	

	set("exits", ([
		"north" : __DIR__"road2",
		"south" :"/d/guanwai/xuedi2",
	]));
	setup();
	replace_program(ROOM);
}

