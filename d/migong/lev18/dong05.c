
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", GRN"�Ŵ��ż�"NOR);
	set("long", GRN @LONG
   �����Ǹ�Σ�յ����򣬺ܴ��Һ�������·���Ӳ������������ľ������
��֪�������ڳ���һЩ����֮�⻹ס��ר������ͷ�İ����壬�Ѿ��в���
�����ȥ֮���û�л�������
LONG NOR);
set("magicroom",1);set("outdoors","migong");
set("magicset",1);
	set("exits", ([
		"east" : __DIR__"dong0"+(random(4)+4),
                "west" : __DIR__"dong0"+(random(4)+3),
		"south" : __DIR__"dong0"+(random(4)+3),
                "north" : __DIR__"dong0"+(random(4)+4),
	]));
if (random(3)==0)
	set("exits", ([
		"westeast" : __DIR__"dong0"+(random(4)+3),
		"eastsouth" : __DIR__"dong0"+(random(4)+4),
                "northwest" : __DIR__"dong0"+(random(4)+3),
                "southnorth" : __DIR__"dong0"+(random(4)+3),
	]));
         set("objects", ([
              __DIR__"npc/lev1" : random(4),
              __DIR__"npc/lev2" : random(4),
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
