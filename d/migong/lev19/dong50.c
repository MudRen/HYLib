
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"�绯֮��"NOR);
	set("long", HIY @LONG
  �����Ƿ绯֮�ҵľ�ͷ!!���֮�������ļ�!!
   ������ط�,����ʮ�ֵ�ǿ��,������һ����ȴ������������,������
����ɢ������,���Ѿ��޷����������ĵ�����,����С�������վ����
�ⱻǿ���ķ��ƴ����Ǹ�����������Ԩ.
LONG NOR);
set("magicroom",1);set("outdoors","migong");
        set("outdoors", "migong");
set("magicset",1);
	set("exits", ([
		"west" : __DIR__"dong49",
                "east" : __DIR__"dong49",
	]));
if (random(2)==0)
	set("exits", ([
		"south" : __DIR__"dong49",
                "north" : __DIR__"dong49",
	]));
         set("objects", ([
              __DIR__"npc/lev5" : 1,
              __DIR__"npc/lev8" : 1,
              __DIR__"npc/lev9" : 3,
              __DIR__"npc/player" : 2,
              __DIR__"npc/boss2" : 1,
              "/clone/box/gboxm" : random(2),
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

