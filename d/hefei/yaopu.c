
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ҩ��");
  set ("long", @LONG
������һ��ҩ�̡����ҩ���ںϷ��кܺõ��������ټ�����ս����
�����������������һֱ�ܺá�
LONG);

  set("exits", ([ 
	  "southeast":__DIR__"xidajie1",
   ]));

  set("objects",([
	  __DIR__"npc/ding":1,
	  ]));
  
  set("valid_startroom", 1);
  setup();
 
}

