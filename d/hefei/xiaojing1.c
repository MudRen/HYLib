
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","С��");
  set ("long", @LONG
��������С���������ǺϷʵ������ˡ���������˺ܶࡣ�������
һƬ�������Ĵ���ȥһƬƽ̹����ʱ����������ͷ�Ϸɹ���
LONG);

  set("exits", ([ 

  "north":__DIR__"nanmen",
  "southwest":__DIR__"xiaojing2",
       ]));
  
set("outdoors","hefei");
  
  set("valid_startroom", 1);
  setup();
 
}

