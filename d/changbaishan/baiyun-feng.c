
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","���Ʒ�");
  set ("long", @LONG
���ű�ѩ�У����ˡ��Է�Ͳ�ҩ�˵��㼣��������˳���ɽ������
�����Ʒ塱�����Ʒ��ֽС����ҡ���������ȥ�����һ���������Ⱥɽ
֮�С�
LONG);

  set("exits", ([ 
 "eastdown":__DIR__"tianchi",
 "southwest":__DIR__"yuzhu-feng",
 "northeast":__DIR__"luming-feng",
 "southdown":__DIR__"pubu"
         ]));
  set("objects",([
   __DIR__"npc/erlengzi":1,
  ]));
  
  set("outdoors","cbs");
  
  set("valid_startroom", 1);
  setup();
 
}

