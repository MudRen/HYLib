// Room: /d/yunhe/chuandi
// Date: netkill  98/08/18

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short","��������" );
    set("long",  @LONG
����һ�䴬�����ң��ں����ģ�û��һ�������
LONG 
    );
	set("exits", ([
		"up" :__DIR__"ship",
			]));
     set("objects", ([
		"quest/weiguo/japan/japan1.c" : 2,
"quest/weiguo/japan/japan3.c" : 1,
	]));   
    set("outdoors", "yunhe");
    setup();
		
}

