inherit ROOM;

void create()
{
	set("short", "���ߵ�");
	set("long", @LONG
��������ʯ�̳ɵ�С·�ϣ��Ա��ǻʹ��Ĺ�ǽ����ǽ�����ߣ�����
����ǽ�����ľ����ϸ����������ǽ�����Ϸ����
LONG );

	set("exits", ([
		"northeast"      : __DIR__"dongdajie",
		"southwest"      : __DIR__"houqiang",
		
	]));


 	set("outdoors", "xuzhou");
	setup();
	replace_program(ROOM);
}



