
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
		"west" : __DIR__"dong32",
                "east" : __DIR__"dong37",
		"south" : __DIR__"dong35",
                "north" : __DIR__"dong39",

	]));
if (random(3)==0)
	set("exits", ([
		"south" : __DIR__"dong33",
                "north" : __DIR__"dong32",
		"west" : __DIR__"dong34",
                "east" : __DIR__"dong39",
	]));
         set("objects", ([
              __DIR__"npc/lev4" : random(4),
              __DIR__"npc/lev3" : 2,

         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

