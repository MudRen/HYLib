
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
		"south" : __DIR__"dong1"+(random(7)+1),
                "north" : __DIR__"dong51",
		"east" : __DIR__"dong1"+(random(7)+1),
                "west" : __DIR__"dong17",
	]));
if (random(3)==0)
	set("exits", ([
		"eastwest" : __DIR__"dong1"+(random(3)+6),
                "southwest" : __DIR__"dong1"+(random(5)+3),
"east" : __DIR__"dong51",
	]));
if (random(2)==1)
	set("exits", ([
		"south" : __DIR__"dong1"+(random(3)+6),
                "north" : __DIR__"dong1"+(random(5)+3),
"west" : __DIR__"dong51",
	]));

	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
