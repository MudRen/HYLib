// ѩ·3
// by steel 

inherit ROOM;

void create()
{
	set("short", "ѩԭ");
	set("long", @LONG
	�����Ǳ�����һƬѩԭ,��ѩ���겻��,������ȥ,��ãã��һƬ,
һ����ӰҲ��������ֻ������ԶԶ����һЩߺ������   
LONG
	);

	set("exits", ([
		"east" : __DIR__"road2",
		"west" : __DIR__"littlehotel",
	]));
	setup();
	replace_program(ROOM);
}

