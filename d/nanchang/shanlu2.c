
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɽ·");
  set ("long", @LONG
�����Ǹ�ɽ·��������һ��ɽ�ԣ�����ɽ�ԣ��Ϳ��Ե��Ž��ˡ���
����һ�����Ĵ�·��
LONG);

  set("exits", ([ 
 "east":__DIR__"shanlu1",
 "west":__DIR__"dalu1",
       ]));

set("outdoors","nanchang");
  
  set("valid_startroom", 1);
  setup();
 
}

