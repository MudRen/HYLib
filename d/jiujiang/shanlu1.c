
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɽ·");
  set ("long", @LONG
��������ɽ·��������ǽ��������ϵĽ����ˡ�
LONG);

  set("exits", ([ 
 "northeast":__DIR__"tulu2",
 "southwest":__DIR__"shanlu2",
 "south":"/d/baling/tulu3",
 "north":__DIR__"nanmen",	
         ]));
  set("outdoors","jiujiang"); 
  set("valid_startroom", 1);
  setup();
 
}

