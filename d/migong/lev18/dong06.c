
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
		"east" : __DIR__"dong05",
		"south" : __DIR__"dong0"+(random(4)+6),
                "west" : __DIR__"dong06",
                "north" : __DIR__"dong0"+(random(4)+4),
	]));
if (random(2)==0)
	set("exits", ([
		"westeast" : __DIR__"dong0"+(random(4)+4),
		"eastsouth" : __DIR__"dong0"+(random(4)+4),
                "northwest" : __DIR__"dong07",
                "southnorth" : __DIR__"dong0"+(random(4)+4),
	]));
         set("objects", ([
              __DIR__"npc/player" : random(4),
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
