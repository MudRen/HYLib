
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short","�ƺӶɿ�");
  set ("long", @LONG
�����ǻƺ������Ķɿڡ���ǰ�ǹ����Ļƺӣ�ֻ�м�������������
�ڶ����������ˡ�
LONG);

  set("exits", ([ 
"east":__DIR__"dukou1",
  "west":__DIR__"road8",
         ]));
set("outdoors","taiyuan");
  set("valid_startroom", 1);
  setup();
 
}

