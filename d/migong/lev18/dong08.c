
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
		"east" : __DIR__"dong09",
		"south" : __DIR__"dong0"+(random(9)+1),
                "west" : __DIR__"dong0"+(random(9)+1),
                "north" : __DIR__"dong0"+(random(8)+1),
	]));
if (random(2)==0)
	set("exits", ([
		"south" : __DIR__"dong0"+(random(9)+1),
                "north" : __DIR__"dong09",
	]));
if (random(2)==0)
	set("exits", ([
		"west" : __DIR__"dong0"+(random(9)+1),
                "east" : __DIR__"dong09",
	]));
         set("objects", ([
              __DIR__"npc/player" : random(4),
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
