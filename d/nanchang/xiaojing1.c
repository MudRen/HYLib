
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","С��");
  set ("long", @LONG
������һ��С�����ϱ߾����ϲ��ı����ˡ���������˺ܶ࣬����
ȥ�ϲ����εġ�
LONG);

  set("exits", ([ 

  "southwest":__DIR__"beimen",
  "northeast":__DIR__"xiaojing2",
        ]));
  set("objects",([
	  __DIR__"npc/youke3":1,
	  ]));
set("outdoors","nanchang");
  
  set("valid_startroom", 1);
  setup();
 
}

