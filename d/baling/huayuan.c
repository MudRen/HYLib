
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��԰");
  set ("long", @LONG
������һ������ʦ�ҵĻ�԰���������˸����ʻ�������ͷף�����
���ޡ��ܶ����������ͻ���һ��紵���������˱Ƕ�����
LONG);

  set("exits", ([ 

  
  "west":__DIR__"houyuan",
     ]));
 
set("outdoors","hangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

