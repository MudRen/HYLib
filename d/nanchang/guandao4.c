
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��ʯ�ٵ�");
  set ("long", @LONG
������һ���������ϣ��������ﻨ�㣬�ο�����������������
���ò����֡�
LONG);

  set("exits", ([ 
  "west":__DIR__"guandao3",
  "east":__DIR__"guandao5",
        ]));
 
set("outdoors","nanchang");
  
  set("valid_startroom", 1);
  setup();
 
}

