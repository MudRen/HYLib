// Room: /u/dubei/u/gumu/jqg/sl1
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
                "northup" : __DIR__"sl2",
                "southdown" : __DIR__"st",
	]));
 

        set("outdoors", "����");
	setup();
	replace_program(ROOM); 
}

