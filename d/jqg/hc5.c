// Room: /u/dubei/u/gumu/jqg/hc5
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
		"south" : __DIR__"hc6",
		"east" : __DIR__"hc"+(random(10)+1),
		"north" : __DIR__"hc"+(random(10)+1),
		"west" : __DIR__"hc"+(random(10)+1),
		"northeast" : __DIR__"hc4",
                "southwest" : __DIR__"hc"+(random(10)+1),
	]));

      set("outdoors", "����");
        replace_program(ROOM);

	setup();

}
 
