
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"ǰ���Ĺ���"NOR);
	set("long", HIY @LONG
  ������һ���ѷ�������ļ�̳.������Ȼ�м�����ж�,
ĳ�����ƺ���������������һ�����ܵļ���.��̳������һ
�������һ���ȼ������
LONG NOR);
        set("outdoors", "migong");
set("magicroom",1);set("outdoors","migong");
set("magicset",1);
	set("exits", ([
		"southup" : __DIR__"dong40",
                "northdown" : __DIR__"dong3"+(random(4)+5),
		"westsouth" : __DIR__"dong3"+(random(4)+5),
                "eastnorth" : __DIR__"dong3"+(random(4)+5),

	]));
if (random(2)==0)
	set("exits", ([
		"southup" : __DIR__"dong3"+(random(4)+5),
                "northdown" : __DIR__"dong3"+(random(4)+5),
		"westsouth" : __DIR__"dong3"+(random(4)+5),
                "eastnorth" : __DIR__"dong40",
	]));
         set("objects", ([
              __DIR__"npc/lev1" : 3,
              __DIR__"npc/lev3" : 2,
              __DIR__"npc/lev2" : 3,
              "/clone/box/gboxm" : random(2),
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}