
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
	set("exits", ([
		"south" : __DIR__"dong3"+(random(9)+1),
                "north" : __DIR__"dong3"+(random(6)+4),
		"west" : __DIR__"dong42",
                "east" : __DIR__"dong45",
	]));
if (random(3)==0)
	set("exits", ([
		"north" : __DIR__"dong45",
		"south" : __DIR__"dong4"+(random(6)+1),
                "north" : __DIR__"dong3"+(random(6)+4),
		"west" : __DIR__"dong4"+(random(6)+1),
                "east" : __DIR__"dong3"+(random(6)+4),
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

