
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��԰");
  set ("long", @LONG
������һ����԰���������˸����ʻ�������ͷף����涷�ޡ��ܶ�
���������ͻ���һ��紵���������˱Ƕ�����
LONG);

  set("exits", ([ 

  "south":__DIR__"tingyuan",
  "north":__DIR__"chaifang",
  "west":__DIR__"caodi",
     ]));
 
set("outdoors","nanchang");
  
  set("valid_startroom", 1);
  setup();
 
}

