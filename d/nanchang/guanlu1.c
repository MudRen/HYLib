
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��·");
  set ("long", @LONG
�����ǹ�·�����߾��ǾŽ��Ķ����ˡ�����������Ѿ��ܶ��ˡ���
����Լ���Կ����Ž��ĳ����ˡ�
LONG);

  set("exits", ([ 
 "southeast":__DIR__"dalu1",
 "west":"/d/jiujiang/dongmen",
       ]));

set("outdoors","nanchang");
  
  set("valid_startroom", 1);
  setup();
 
}

