
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɽ·");
  set ("long", @LONG
�����Ǹ�ɽ·����������ɽ�ԣ����߲�Զ�����ǾŽ��ˣ����߾Ϳ�
�Ե��ϲ��ˡ�
LONG);

  set("exits", ([ 
 "eastup":__DIR__"shangang2",
 "west":__DIR__"shanlu2",
       ]));

set("outdoors","nanchang");
  
  set("valid_startroom", 1);
  setup();
 
}

