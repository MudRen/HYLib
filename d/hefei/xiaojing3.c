
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","С��");
  set ("long", @LONG
��������С���������ǰ��յ��ϲ��ˡ�ƽʱ�н�����������Ѳ�ߣ�
�㲻��С��������
LONG);

  set("exits", ([ 

  "northeast":__DIR__"xiaojing2",
  "south":__DIR__"shanlu1",
       ]));
  set("objects",([
	  __DIR__"npc/jun":2,
	  ]));
set("outdoors","hefei");
  
  set("valid_startroom", 1);
  setup();
 
}

