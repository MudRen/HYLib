
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIG"����֮ɭ"NOR);
	set("long", HIG @LONG
    ������һ�����ϵ�ԭʼɭ�֣������������ľ���������ǹ��϶�
��ɣ���ݷ������������µ�ĥ��������������ɭ�ֲ����ϣ�������ݺ
�������в����ܷҶྫ��޹�ա�
LONG NOR);
set("magicroom",1);set("outdoors","migong");
set("magicset",1);


	set("exits", ([
		"east" : __DIR__"dong06",
		"south" : __DIR__"dong0"+(random(4)+4),
                "west" : __DIR__"dong05",
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
              __DIR__"npc/player" : random(3),
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
