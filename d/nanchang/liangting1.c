
inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short","С��ͤ");
  set ("long", @LONG
����������ͤ�����ο���Ϣ֮�á�������������ӭ���������
������һ���������������ݵı��Ų�Զ���羰���ˣ������������ο�
�����١�
LONG);

  set("exits", ([ 
 "southeast":__DIR__"lvyinlu",
         ]));
   set("objects",([
     __DIR__"npc/xiaojie1":1,
     ]));
set("outdoors","nanchang");
  
  set("valid_startroom", 1);
  setup();
 
}
