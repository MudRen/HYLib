// Room: /u/dubei/u/gumu/jqg/sl2
// by dubei
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
����һ�����͵�ɽ·�����ɽ���Ѷ�ȥ��
LONG
	);

	set("exits", ([
                "westup" : __DIR__"sl3",
                "southdown" : __DIR__"sl1",
	]));
 

        set("outdoors", "����");
	setup();
	replace_program(ROOM); 
}

