// Room: /u/dubei/u/gumu/jqg/qs
// by dubei
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���ǹ���ֹ��˯��������Ĵ�����޳�У�����վ��һ��Ѿ�ߣ�
�����뿪�����ڹ��߲�̫������
LONG
	);

	set("exits", ([
                "south" : __DIR__"zl1",
	]));

        set("objects", ([
		__DIR__"npc/yahuan" : 1,
	 ]));
	setup();
	replace_program(ROOM); 
}

