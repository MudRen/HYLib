
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
		"south" : __DIR__"dong02",
                "north" : __DIR__"dong0"+(random(3)+1),
		"east" : __DIR__"dong02",
                "west" : "/d/migong/lev17/dong21",
	]));
set("no_npc",1);
         set("objects", ([
              __DIR__"npc/lev5" : random(3),
         ]));
if (random(2)==0)
	set("exits", ([
		"east" : __DIR__"dong0"+(random(3)+1),
                "west" : "/d/migong/lev17/dong21",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
