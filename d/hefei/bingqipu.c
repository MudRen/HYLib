
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","������");
  set ("long", @LONG
������һ�ұ����̡�������ս��������������������һֱ�ܺá�
����������æ����ͣ��
LONG);

  set("exits", ([ 
	  "north":__DIR__"dongdajie3",
    ]));

  set("objects",([
	  __DIR__"npc/tiejiang":1,
	  ]));
  set("valid_startroom", 1);
  setup();
 
}

