
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","���շ�");
  set ("long", @LONG
���շ�λ����ض��ϡ����������塣�����嶥�ж�ֱͨ��أ���
���кܶ���ɫʯ�����޹������˰������֣�
LONG);

  set("exits", ([ 
 "west":__DIR__"gusun-feng",
 "south":__DIR__"wohu-feng",
 "northwest":__DIR__"pingjin-feng",
         ]));
  set("objects",([
   __DIR__"npc/youke":2,
  ]));
  
  set("outdoors","cbs");
  
  set("valid_startroom", 1);
  setup();
 
}

