
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short","۶��������");
  set ("long", @LONG
������۶�����Ķ���������ɻ���㣬����ƽ���羵����ʱ���οʹ�
�����߹���
LONG);

  set("exits", ([ 
 "south":__DIR__"dongan1",
        ]));

set("outdoors","nanchang");
  
  set("valid_startroom", 1);
  setup();
 
}
