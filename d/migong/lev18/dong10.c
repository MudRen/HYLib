
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
		"east" : __DIR__"dong0"+(random(6)+2),
		"south" : __DIR__"dong0"+(random(6)+3),
                "west" : __DIR__"dong0"+(random(6)+3),
                "north" : __DIR__"dong1"+(random(3)+1),
	]));
         set("objects", ([
              __DIR__"npc/lev2" : random(3),
              "/clone/box/gboxm" : 1,
              __DIR__"npc/lev2" : random(3),
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
