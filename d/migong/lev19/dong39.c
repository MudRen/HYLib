
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
        set("outdoors", "migong");
set("magicroom",1);set("outdoors","migong");
set("magicset",1);
	set("exits", ([
		"south" : __DIR__"dong40",
                "north" : __DIR__"dong3"+(random(4)+5),
		"west" : __DIR__"dong3"+(random(4)+5),
                "east" : __DIR__"dong3"+(random(4)+5),

	]));
if (random(2)==0)
	set("exits", ([
		"south" : __DIR__"dong3"+(random(4)+5),
                "north" : __DIR__"dong3"+(random(4)+5),
		"west" : __DIR__"dong3"+(random(4)+5),
                "east" : __DIR__"dong40",
	]));
         set("objects", ([
              __DIR__"npc/lev1" : 1,
              __DIR__"npc/lev3" : 1,
              __DIR__"npc/lev2" : 1,
              "/clone/box/gboxm" : random(2),
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}