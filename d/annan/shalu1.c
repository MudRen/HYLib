
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɳʯ·");
  set ("long", @LONG
��������ɳʯ·��һ��紵�������������ɳ������ʱ���������
�����Գ۹���
LONG);

  set("exits", ([ 

  "northeast":__DIR__"wguanlu1",
  "southwest":__DIR__"shalu2",
       ]));

set("outdoors","annan");
  
  set("valid_startroom", 1);
  setup();
 
}

