
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","果林");
  set ("long", @LONG
这里是一大片果树林，四周果树林立，传来阵阵的水果芳香。使人
不自觉的留出了口水。旁边各种昆虫飞来飞去，偶尔有几只小动物从身
旁串过，让你留连忘返。
LONG);

  set("exits", ([ 

  "south":__DIR__"guolin",
        ]));
 
set("outdoors","nanchang");
  
  set("valid_startroom", 1);
  setup();
 
}

