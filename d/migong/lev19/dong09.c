
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIG"����֮ɭ"NOR);
	set("long", HIY @LONG
    ������һ�����ϵ�ԭʼɭ�֣������������ľ���������ǹ��϶�
��ɣ���ݷ������������µ�ĥ��������������ɭ�ֲ����ϣ�������ݺ
�������в����ܷҶྫ��޹�ա�
LONG NOR);


	set("exits", ([
		"east" : __DIR__"dong0"+(random(9)+1),
		"south" : __DIR__"dong0"+(random(9)+1),
                "west" : __DIR__"dong0"+(random(9)+1),
                "north" : __DIR__"dong10",
	]));
if (random(2)==0)
	set("exits", ([
                "south" : __DIR__"dong10",
		"north" : __DIR__"dong0"+(random(9)+1),
	]));
if (random(2)==0)
	set("exits", ([
                "west" : __DIR__"dong10",
		"east" : __DIR__"dong0"+(random(9)+1),
	]));

         set("objects", ([
              __DIR__"npc/player" : random(2),
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
