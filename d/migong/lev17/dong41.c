
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", BLU"ˮ��֮��"NOR);
	set("long", BLU @LONG
    �������ں����ϣ��������ϡ����������ꡣ����������һ���ŵķ����֣�֦��
��Ӳ��ϸϸ����ģ���ľ���һ���ֲ�������һƬ����Ĵ󺣣����˲�ͣ����
�����µ̡�
LONG NOR);
        set("outdoors", "migong");
set("magicroom",1);set("outdoors","migong");
set("magicset",1);
	set("exits", ([
		"west" : __DIR__"dong3"+(random(6)+4),
                "east" : __DIR__"dong4"+(random(3)+2),
		"south" : __DIR__"dong3"+(random(6)+4),
                "north" : __DIR__"dong3"+(random(6)+4),
	]));
if (random(3)==0)
	set("exits", ([
		"west" : __DIR__"dong4"+(random(3)+2),
                "east" : __DIR__"dong3"+(random(6)+4),
		"south" : __DIR__"dong3"+(random(6)+4),
                "north" : __DIR__"dong3"+(random(6)+4),
	]));
         set("objects", ([
              __DIR__"npc/lev2" : 1,
              __DIR__"npc/lev5" : 3,
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

