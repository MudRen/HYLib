// ѩ·2
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
		"south" : __DIR__"road1",
		"west" :__DIR__"road3",
                "north" :__DIR__"road4",
                "northwest" :__DIR__"road5", 
               ]));
	setup();
	replace_program(ROOM);
}

