
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��·");
  set ("long", @LONG
�����������Ĵ�·�����߿��������Ž��ĳ����ˡ���������˽�
������������
LONG);

  set("exits", ([ 
 "east":__DIR__"shanlu2",
 "northwest":__DIR__"guanlu1",
       ]));

set("outdoors","nanchang");
  
  set("valid_startroom", 1);
  setup();
 
}

