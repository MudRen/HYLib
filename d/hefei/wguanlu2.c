
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��·");
  set ("long", @LONG
����������·���������������ǳ���æ����ʱ����������ҴҶ�����
�����ǺϷʵ���������ʱ�д�ӵĹٱ�����������߹�����ͷ�Ľ��첻ʱ
��ͷ�������㡣
LONG);

  set("exits", ([ 

  "northeast":__DIR__"wguanlu1",
  "west":__DIR__"tulu1",
       ]));
 
set("outdoors","hefei");
  
  set("valid_startroom", 1);
  setup();
 
}

