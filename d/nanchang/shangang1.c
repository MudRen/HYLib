
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɽ��");
  set ("long", @LONG
�����Ǹ�ɽ�ԡ��������˺��١������ǽ����ľ����ˡ����紵����
�㲻�����˸���ս��
LONG);

  set("exits", ([ 
 "east":__DIR__"tulu2",
 "southwest":__DIR__"shangang2",
 "north":__DIR__"caocong1",
        ]));

set("outdoors","nanchang");
  
  set("valid_startroom", 1);
  setup();
 
}

