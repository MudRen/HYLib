// Room: /u/dubei/u/gumu/jqg/df
// by dubei
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����Ǿ�������Ƶ�ҩ�ĵط�������������һ�ɴ̱�
��ҩζ��
LONG
	);

	set("exits", ([
 
                "south" : __DIR__"zl2",
	]));
 

  
	setup();
	replace_program(ROOM); 
}

