
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
                "west" : __DIR__"dong1"+(random(5)+1),
		"east" : __DIR__"dong1"+(random(5)+1),
		"south" : __DIR__"dong1"+(random(3)+1),
                "north" : __DIR__"dong1"+(random(4)+1),
	]));
if (random(3)==0)
	set("exits", ([
                "west" : __DIR__"dong1"+(random(5)+1),
		"east" : __DIR__"dong1"+(random(5)+1),
	]));
if (random(3)==1)
	set("exits", ([
		"south" : __DIR__"dong1"+(random(5)+1),
                "north" : __DIR__"dong1"+(random(5)+1),
	]));

         set("objects", ([
              __DIR__"npc/lev5" : random(3),
              "/clone/box/gboxm" : random(2),
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}