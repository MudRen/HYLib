// luzhou.c ����
// go town & mingjiao & tianshan
// Ver 0.1 08/14/1998 by Freeze

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIG "�� ��");
	set("long",  @LONG
����ããɳĮ��ͻȻ��������������������˷ܲ��ѣ���·��ƣ���ƺ���̼�
ɢȥ�����������Ϸ�����һ��С�������Ϳ��Ե���ɽ�ˡ�
LONG
	);	
        set("outdoors", "jyguan");


	set("exits", ([
		"west" : __DIR__"luzhou1",
//              	"east" : __DIR__"shamo",
//                "south" : __DIR__"shanlu",
                "north" : "/d/suiye/caoyuan",
                "northwest" : __DIR__"shaqiu2",
//                "northeast" : __DIR__"shaqiu1",
//                "southwest" : __DIR__"shqiu2",
                "southeast" : __DIR__"town",
	]));
	
		
	setup();
	replace_program(ROOM);
}

