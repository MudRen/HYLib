
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��·");
  set ("long", @LONG
�����������Ĵ�·������������������ĳ�ǽ�ˡ�����������·��
����������Ѿ��ܶ��ˡ�
LONG);

  set("exits", ([ 

  "southwest":__DIR__"dalu1",
  "northeast":"/d/xiangyang/caodi3",
       ]));
 
set("outdoors","hefei");
  
  set("valid_startroom", 1);
  setup();
 
}

