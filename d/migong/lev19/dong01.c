
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
		"south" : __DIR__"dong02",
                "north" : __DIR__"dong0"+(random(3)+1),
		"west" : __DIR__"dong02",
                "east" : "/d/migong/lev18/dong21",
	]));
set("no_npc",1);
         set("objects", ([
              __DIR__"npc/lev4" : random(3),
         ]));
if (random(2)==0)
	set("exits", ([
		"east" : __DIR__"dong0"+(random(3)+1),
                "west" : "/d/migong/lev18/dong21",
	]));
if (random(2)==0)
	set("exits", ([
		"south" : "/d/migong/lev18/dong21",
                "north" : __DIR__"dong0"+(random(3)+1),
	]));

	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
