
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","������");
  set ("long", @LONG
�����Ǽұ����ꡣ�������ڴ���ս��ʱ�ڣ�������������ܺá�ֻ
�������������ô���Աߵ��ϵĽ���������˸��ֱ����ͻ��ס�ֻ��
ƹ�����У���һ������������ˡ�
LONG);

  set("exits", ([ 

  "west":__DIR__"suishilu2",
     ]));
 
  set("objects",([
	  __DIR__"npc/tiejiang":1,
	  ]));  
  
  set("valid_startroom", 1);
  setup();
 
}

