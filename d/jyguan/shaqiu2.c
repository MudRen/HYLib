// shaqiu2.c ɳ��
// shamo can to shaqiu
// Ver 0.1 08/14/1998 by Freeze

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIG "ɳ ��");
	set("long",  @LONG
����������ɳ����Ե��ɳ����������Կ�����ϡ��Ĺ�ľ��һ������Ϳ��ܴ���ɳĮ�ش���
������ͨ����ɽ���ִ�����ص�Ψһ·����
LONG
	);	
        set("outdoors", "jyguan");


	set("exits", ([
//		"west" : __DIR__"shamo1",
//		"east" : __DIR__"shamo",
//                "south" : __DIR__"shamo",
                "north" : __DIR__"shamo",
                "northwest" : __DIR__"shamo",
                "northeast" : __DIR__"shaqiu1",
//                "southwest" : __DIR__"shqiu2",
                "southeast" : __DIR__"luzhou",
	]));
	
		
	setup();
	replace_program(ROOM);
}

