
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
set("magicroom",1);set("outdoors","migong");
set("magicset",1);
set("outdoors", "migong");
	set("exits", ([
                "west" : __DIR__"dong3"+(random(5)+4),
		"east" : __DIR__"dong3"+(random(5)+5),
		"south" : __DIR__"dong3"+(random(5)+4),
                "north" : __DIR__"dong3"+(random(5)+4),
	]));
if (random(2)==0)
	set("exits", ([
		"east" : __DIR__"dong3"+(random(5)+5),
                "west" : __DIR__"dong3"+(random(5)+4),
	]));

         set("objects", ([
              __DIR__"npc/lev3" : random(5),
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

