
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","������");
  set ("long", @LONG
������ǳ���ʮ�����еĵġ������塱����������һֻ��ӥ����
����ɽ�ƶ��ͣ�Ҫ����ɽҪ���С�ġ�  
LONG);

  set("exits", ([ 
 "east":__DIR__"guanri-feng",
 "north":__DIR__"pingjin-feng",
         ]));
  set("outdoors","cbs");
  
  set("valid_startroom", 1);
  setup();
 
}

