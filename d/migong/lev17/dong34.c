
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
		"east" : __DIR__"dong33",
		"west" : __DIR__"dong35",
	]));
if (random(2)==0)
	set("exits", ([
		"south" : __DIR__"dong35",
                "north" : __DIR__"dong33",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

