
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�÷��");
  set ("long", @LONG
������һ�Ҳ÷�ꡣ������·������ܺã��ںϷ��кܸߵ�������
�кܶ������������·����ϰ�æ����ͣ��
LONG);

  set("exits", ([ 
  "north":__DIR__"xidajie2",
   ]));

  set("objects",([
	  __DIR__"npc/zhang":1,
	  ]));
  set("valid_startroom", 1);
  setup();
 
}

