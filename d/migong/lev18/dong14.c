
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
                "west" : __DIR__"dong1"+(random(5)+1),
		"east" : __DIR__"dong1"+(random(3)+4),
		"south" : __DIR__"dong1"+(random(4)+1),
                "north" : __DIR__"dong15"
	]));
if (random(4)==0)
	set("exits", ([
		"east" : __DIR__"dong1"+(random(3)+4),
                "west" : __DIR__"dong1"+(random(3)+3),
	]));
if (random(3)==1)
	set("exits", ([
		"south" : __DIR__"dong1"+(random(5)+4),
                "north" : __DIR__"dong1"+(random(5)+1),
	]));

         set("objects", ([
              __DIR__"npc/lev4" : random(6),
              __DIR__"npc/lev5" : random(6),
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}