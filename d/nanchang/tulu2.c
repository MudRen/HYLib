
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��·");
  set ("long", @LONG
����������·�������ǽ����ľ��أ������߾��ǾŽ���
�����ˡ�
LONG);

  set("exits", ([ 
 "northeast":__DIR__"tulu1",
 "west":__DIR__"shangang1",
        ]));

set("outdoors","nanchang");
  
  set("valid_startroom", 1);
  setup();
 
}

