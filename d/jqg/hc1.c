// Room: /u/dubei/u/gumu/jqg/hc1
// by dubei

#include <room.h>
inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
������һƬ���ԣ���е��Ѿ����ѱ����·�ˡ�
LONG
	);

	set("exits", ([
		"north" : __DIR__"hc"+(random(10)+1),
		"south" : __DIR__"hc2",
		"west" : __DIR__"hc"+(random(10)+1),
		"east" : __DIR__"hc"+(random(10)+1),
		"out" : __DIR__"wx",
	]));

      set("outdoors", "xiangyang");
          replace_program(ROOM);

	setup();

}
 
