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
		"northeast" : __DIR__"linhai"+(random(13)+1),
		"southwest" : __DIR__"linhai2",
		"northwest" : __DIR__"linhai"+(random(13)+1),
		"southeast" : __DIR__"linhai"+(random(13)+1),
		"down" : __DIR__"conglin4",
	]));

      set("outdoors", "xiangyang");
           replace_program(ROOM);
           setup();

}
 
