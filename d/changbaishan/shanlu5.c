
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɽ·");
  set ("long", @LONG
������һ��ɽ·��̧ͷ��ȥ�����߾���Ѽ�̽����������Զ�ˡ�
LONG);

  set("exits", ([ 
 "down":__DIR__"shanlu4",
 "north":"/d/gaoli/jiangnan",
         ]));
  set("outdoors","cbs");
  
  set("valid_startroom", 1);
  setup();
 
}

