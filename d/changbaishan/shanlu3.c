
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɽ·");
  set ("long", @LONG
������һ��ɽ·��������һ��ɽ�£�������һƬ�����֡����滹��
·��̧ͷ��ȥ��������Լ��һ�����
LONG);

  set("exits", ([ 
 "eastup":__DIR__"shanlu4",
 "west":__DIR__"shanya",
 "east":__DIR__"shulin2",
 "down":__DIR__"shulin1",
         ]));
  set("outdoors","cbs");
  
  set("valid_startroom", 1);
  setup();
 
}

