
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","С·");
  set ("long", @LONG
��������С·��·���������˺ܶ����������ܴ����ܲ����ʻ��̲�
�������֣�����ɽ���ﴵ����������磬������������������һЩ����
�Ļ��㣬���߲�Զ������۶�����ˡ���ʱ���ο͵��������߹���
LONG);

  set("exits", ([ 
 "northeast":__DIR__"xiaolu2",
 "southwest":__DIR__"tulu1",
        ]));

set("outdoors","nanchang");
  
  set("valid_startroom", 1);
  setup();
 
}

