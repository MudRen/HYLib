
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"����"NOR);
  set ("long", @LONG
�������ϲ������š��ϲ�������ʤ�أ�������������˺ܶࡣ����
�������ٱ����ڼ�������������ˡ�
LONG);

  set("exits", ([ 

  "north":__DIR__"nandajie2",
  "south":"/d/changsha/road8",
        ]));
  set("objects",([
	  __DIR__"npc/bing":2,
	  ]));
set("outdoors","nanchang");
  
  set("valid_startroom", 1);
  setup();
 
}

