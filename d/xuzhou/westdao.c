inherit ROOM;

void create()
{
	set("short", "���ߵ�");
	set("long", @LONG
��������ʯ�̳ɵ�С·�ϣ��Ա��ǻʹ��Ĺ�ǽ����ǽ�����ߣ�����
����ǽ�����ľ����ϸ����������ǽ�����Ϸ����
LONG );

	set("exits", ([
		"northwest"      : __DIR__"xidajie",
		"southeast"      : __DIR__"houqiang",
		"west":__DIR__"yanju",
		
	]));
        set("objects",([
     "/clone/npc/man":1,
     ]));

 	set("outdoors", "xuzhou");
	setup();
	replace_program(ROOM);
}



