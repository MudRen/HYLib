
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","С·");
  set ("long", @LONG
��������С·��·���������˺ܶ����������ܴ����ܲ����ʻ��̲�
�������֣�����ɽ���ﴵ����������磬������������������һЩ����
�Ļ��㣬���߾���۶�����ˡ�
LONG);

  set("exits", ([ 
 "east":__DIR__"nanan2",
 "west":__DIR__"xiaolu2",
 "north":__DIR__"baiti",
        ]));

set("outdoors","nanchang");
  
  set("valid_startroom", 1);
  setup();
 
}

