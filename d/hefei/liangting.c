
inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short","С��ͤ");
  set ("long", @LONG
����������ͤ�����ο���Ϣ֮�á�������������ӭ���������
������һ���Ա���һ���峺��С�Ӵ��ŵ������������������������
�Ŀ������·�������������Դ��
LONG);

  set("exits", ([ 
 "north":__DIR__"xiaoqiao",
         ]));
   set("objects",([
       __DIR__"npc/gongzi":1,
       ]));
set("outdoors","hefei");
  
  set("valid_startroom", 1);
  setup();
 
}
