// shamo1.c ɳĮ
// shamo can to shaqiu
// Ver 0.1 08/14/1998 by Freeze

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIY "ɳĮ");
	set("long", HIY @LONG
����������ããɳ����ɳ���������������ͬ���ľ�ɫ����������ʧ����
��ܿ�ͻ�ɿ����͡�
LONG
NOR	);	
        set("outdoors", "jyguan");


	set("exits", ([
		"west" : __DIR__"shamo",
		"east" : __DIR__"shamo",
                "south" : __DIR__"shamo",
                "north" : __DIR__"shamo",
                "northwest" : __DIR__"shamo",
                "northeast" : __DIR__"shamo",
                "southwest" : __DIR__"shaqiu",
                "southeast" : __DIR__"shamo",
	]));
	
		
	setup();
	replace_program(ROOM);
}

