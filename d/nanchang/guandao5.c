
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��ʯ�ٵ�");
  set ("long", @LONG
������һ���������ϣ��������ﻨ�㣬�ο�����������������
���ò����֡�����쵽�����ˡ�
LONG);

  set("exits", ([ 
  "west":__DIR__"guandao4",
  "east":"/d/hangzhou/road1",
        ]));
 
set("outdoors","nanchang");
  
  set("valid_startroom", 1);
  setup();
 
}

