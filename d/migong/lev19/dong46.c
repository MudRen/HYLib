
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"�绯֮��"NOR);
	set("long", HIY @LONG
   ������ط�,����ʮ�ֵ�ǿ��,������һ����ȴ������������,������
����ɢ������,���Ѿ��޷����������ĵ�����,����С�������վ����
�ⱻǿ���ķ��ƴ����Ǹ�����������Ԩ.
LONG NOR);
set("magicroom",1);set("outdoors","migong");
set("magicset",1);
	set("exits", ([
		"west" : __DIR__"dong47",
                "east" : __DIR__"dong3"+(random(9)+1),
		"south" : __DIR__"dong3"+(random(9)+1),
                "north" : __DIR__"dong42",
	]));
if (random(3)==0)
	set("exits", ([
		"east" : __DIR__"dong4"+(random(4)+4),
                "west" : __DIR__"dong4"+(random(4)+4),
	]));
if (random(3)==0)
	set("exits", ([
		"west" : __DIR__"dong4"+(random(4)+4),
                "east" : __DIR__"dong3"+(random(9)+1),
	]));
         set("objects", ([
              __DIR__"npc/player" : 1,
              __DIR__"npc/lev7" : 1,
              __DIR__"npc/lev1" : 1,
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

