// Room: /u/dubei/u/gumu/jqg/xf
// by dubei
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "�巿");
	set("long", @LONG
�����ǹ���������巿�����������������࣬һ����Ů��
���ڴ�ǰ��˼��
LONG
	);

	set("exits", ([
                "north" : __DIR__"zl2",
 
	]));
	set("objects", ([
		__DIR__"npc/gsle" : 1,
	 ]));

       setup();
   replace_program(ROOM);
}
 
