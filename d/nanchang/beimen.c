
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"����"NOR);
  set ("long", @LONG
�������ϲ��ı��š��ϲ�������ʤ�أ�������������˺ܶࡣ����
�������ٱ����ڼ�������������ˡ�
LONG);

  set("exits", ([ 

  "south":__DIR__"beidajie1",
  "north":__DIR__"lvyinlu",
  "northeast":__DIR__"xiaojing1",
        ]));
  set("objects",([
	  __DIR__"npc/bing":2,
	  ]));
set("outdoors","nanchang");
  
  set("valid_startroom", 1);
  setup();
 
}

