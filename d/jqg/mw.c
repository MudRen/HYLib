// Room: /u/dubei/u/gumu/jqg/mw
// by dubei
#include <ansi.h>; 
inherit ROOM;

void create()
{
	set("short", HIY"é��"NOR);
	set("long", @LONG
ֻ�����г����ª�����ྻ�쳣������ֻһ��һ������
����ޱ�����Ĺʯ���е�����һģһ����
LONG
	);
        set("exits", ([
                "out" : __DIR__"gd2",
        ]));
	set("objects", ([
		__DIR__"npc/yangguo" : 1,
	        __DIR__"npc/xln" : 1,
	]));
        setup();
       replace_program(ROOM);
}
 