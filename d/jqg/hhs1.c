// Room: /u/dubei/u/gumu/jqg/hhs1
// by dubei
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����Ǽ����������ʯ�ң������ͺͺ�Ķ���ʯ�ڡ�ֻ��һ��
С�����΢���Ĺ������������ڣ������޷����ܡ�
LONG
	);

	set("exits", ([
                "out" : __DIR__"hhs",
	]));

        set("objects", ([
		__DIR__"npc/puren" : 1,
	 ]));
	setup();
	replace_program(ROOM); 
}

