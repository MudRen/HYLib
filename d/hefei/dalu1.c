
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��·");
  set ("long", @LONG
�����������Ĵ�·������������Ѿ��ܶ��ˡ���ʱ�����������
��������߹���
LONG);

  set("exits", ([ 

  "south":__DIR__"caodi1",
  "northeast":__DIR__"dalu2",
       ]));
 
set("outdoors","hefei");
  
  set("valid_startroom", 1);
  setup();
 
}

