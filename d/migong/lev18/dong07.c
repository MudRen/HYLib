
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
		"east" : __DIR__"dong0"+(random(5)+4),
		"south" : __DIR__"dong08",
                "west" : __DIR__"dong0"+(random(5)+4),
                "north" : __DIR__"dong04",
	]));
if (random(2)==0)
	set("exits", ([
		"eastsouth" : __DIR__"dong0"+(random(5)+4),
		"southwest" : __DIR__"dong08",
                "westnorth" : __DIR__"dong0"+(random(5)+4),
                "northeast" : __DIR__"dong04",
	]));

         set("objects", ([
              __DIR__"npc/lev3" : random(5),
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
