
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��");
  set ("long", @LONG
�����ǲ񷿣��м������������﹤����ֻ���������������������
������������������������ǡ�
LONG);

  set("exits", ([ 

  "south":__DIR__"huayuan",

     ]));
 
set("outdoors","nanchang");
  
  set("valid_startroom", 1);
  setup();
 
}

