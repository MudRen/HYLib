
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�ݴ�");
  set ("long", @LONG
�����Ǹ��ݴԣ����涼��������·������ֻ�������紵�ݶ���������
�㲻��С��������
LONG);

  set("exits", ([ 
 "south":__DIR__"shangang1",
 "east":__DIR__"caocong2",
      ]));

set("outdoors","nanchang");
  
  set("valid_startroom", 1);
  setup();
 
}

