
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","۶�����ϰ�");
  set ("long", @LONG
������۶�������ϰ���������һ���ţ����Ե�۶�����Ķ����������к�
����������������۶�����ķ�⡣
LONG);

  set("exits", ([ 
 "east":__DIR__"nanan1",
"northeast":__DIR__"hupao",
 "northup":__DIR__"qiao",
 "west":__DIR__"xiaolu1",
 "northeast":__DIR__"hupao",
        ]));

set("outdoors","nanchang");
  
  set("valid_startroom", 1);
  setup();
 
}

