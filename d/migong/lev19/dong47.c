
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
		"west" : __DIR__"dong48",
                "east" : __DIR__"dong4"+(random(9)+1),
		"south" : __DIR__"dong4"+(random(9)+1),
                "north" : __DIR__"dong4"+(random(9)+1),
	]));
if (random(3)==0)
	set("exits", ([
		"south" : __DIR__"dong4"+(random(3)+6),
                "west" : __DIR__"dong4"+(random(3)+6),
	]));
if (random(2)==0)
	set("exits", ([
		"west" : __DIR__"dong4"+(random(9)+1),
                "east" : __DIR__"dong48",
	]));
         set("objects", ([
              __DIR__"npc/lev8" : 1,
              __DIR__"npc/lev9" : 3,
      "/clone/box/gboxm" : random(2),
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

