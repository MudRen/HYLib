
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
 "east":__DIR__"xiaolu1",
 "southwest":__DIR__"xiaolu3",
        ]));
 set("objects",([
	 __DIR__"npc/youke3":1,
	 ]));
set("outdoors","nanchang");
  
  set("valid_startroom", 1);
  setup();
 
}

