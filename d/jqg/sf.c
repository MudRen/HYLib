// Room: /u/dubei/u/gumu/jqg/sf
// by dubei
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "�鷿");
	set("long", @LONG
���ǹ���ֹ���鷿������Ϸ���һЩ�����ؼ���һ�����
�����ܹ�������
LONG
	);

	set("exits", ([
 
                "south" : __DIR__"sqx",
	]));
 

  
	setup();
	replace_program(ROOM); 
}

