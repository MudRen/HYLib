
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��ʯ·");
  set ("long", @LONG
����������ʯ·���ϱ߾��ǰ��ϵ������ˡ�������һ�ұ����꣬��
�ﴫ�����ô����������Ǽұ��������������߳������ܶ�������ʿ��
������ȥ����ס����Ƶȡ�
LONG);

  set("exits", ([ 

  "north":__DIR__"suishilu1",
  "south":__DIR__"nanmen",
  "east":__DIR__"bingqidian",
   "west":__DIR__"hg",
       ]));
 
set("outdoors","annan");
  
  set("valid_startroom", 1);
  setup();
 
}

