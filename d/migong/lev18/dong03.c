
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
		"south" : __DIR__"dong0"+(random(5)+1),
                "north" : __DIR__"dong04",
	]));
         set("objects", ([
              __DIR__"npc/lev2" : random(2),
         ]));
if (random(2)==0)
	set("exits", ([
		"east" : __DIR__"dong0"+(random(4)+1),
                "west" : __DIR__"dong0"+(random(4)+1),
		"south" : __DIR__"dong0"+(random(5)+2),
                "north" : __DIR__"dong04",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
