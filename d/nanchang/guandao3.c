
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
  "east":__DIR__"guandao4",
  "west":__DIR__"conglin3",
        ]));
 
set("outdoors","nanchang");
  
  set("valid_startroom", 1);
  setup();
 
}

