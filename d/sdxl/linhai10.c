// sdxl
// by dubei
#include <room.h>
inherit ROOM;


void create()
{
	set("short", "�ֺ�");
	set("long", @LONG
������һƬһ�������ֺ���ÿ����ľ����ʮ���ɸߣ���Χ��İ
����������о����Լ���·��
LONG
	);
	set("exits", ([
		"northeast" : __DIR__"linhai9",
		"southeast" : __DIR__"linhai"+(random(13)+1),
		"northwest" : __DIR__"linhai"+(random(13)+1),
		"southwest" : __DIR__"linhai"+(random(13)+1),
		"south" : __DIR__"linhai"+(random(13)+1),
		"east" : __DIR__"linhai"+(random(13)+1),
		"north" : __DIR__"linhai"+(random(13)+1),
		"west" : __DIR__"linhai11",
	]));

	set("outdoors", "xiangyang");
	setup();
            replace_program(ROOM);
}
 

