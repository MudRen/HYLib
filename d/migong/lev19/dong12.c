
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
		"east" : __DIR__"dong34",
		"south" : __DIR__"dong1"+(random(3)+1),
                "west" : __DIR__"dong1"+(random(3)+3),
                "north" : __DIR__"dong1"+(random(4)+1),
	]));
if (random(3)==0)
	set("exits", ([
		"east" : __DIR__"dong1"+(random(4)+3),
                "west" : __DIR__"dong1"+(random(3)+1),
	]));
if (random(3)==1)
	set("exits", ([
		"south" : __DIR__"dong34",
                "north" : __DIR__"dong1"+(random(3)+3),
	]));
         set("objects", ([
              __DIR__"npc/lev4" : random(7),
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
