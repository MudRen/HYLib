
#include <room.h>

inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
�����������ŵ����ţ�����������½��ģ�ֻ������һ������ͥ
Ժ��
LONG );
	set("exits", ([
		"south" : __DIR__"nanmen",
                 "northeast" : __DIR__"eastdao",  
                "northwest" : __DIR__"westdao",
		///"east" : "/d/clone/room/cityroom/xucheng",
	]));
	set("objects", ([
		__DIR__"npc/guanbing" : 2,
	]));
	set("outdoors", "xuzhou");
	setup();
	replace_program(ROOM);
}

