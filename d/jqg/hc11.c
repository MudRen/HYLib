// Room: /u/dubei/u/gumu/jqg/hc11
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
		"south" : __DIR__"hc"+(random(10)+1),
		"east" : __DIR__"hc"+(random(10)+1),
		"north" : __DIR__"hc"+(random(10)+1),
		"west" : __DIR__"st",
		"northeast" : __DIR__"hc"+(random(10)+1),
                "southwest" : __DIR__"hc10",
	]));

      set("outdoors", "xiangyang");
     replace_program(ROOM);
    

	setup();

}
 
