// luzhou.c ����
// go town & mingjiao & tianshan
// Ver 0.1 08/14/1998 by Freeze

#include <ansi.h>
#define __RTM__        "/rtm/"
inherit ROOM;

void create()
{
	set("short",HIG "�� ��");
	set("long",  @LONG
�������������������������Ŀ����ǵ���ŵ㡣
��������ȥ��һ��С���������Ե���ɽ��
LONG
	);	
        set("outdoors", "jyguan");


	set("exits", ([
	"west" : __DIR__"wall",
             	"east" : __DIR__"luzhou",
//                "south" : __DIR__"shanlu",
//                "north" : __DIR__"shamo",
//                "northwest" : __DIR__"shaqiu2",
//                "northeast" : __DIR__"shaqiu1",
//                "southwest" : __DIR__"shqiu2",
//                "southeast" : __DIR__"town",
	]));
	
		
	setup();
	replace_program(ROOM);
}

