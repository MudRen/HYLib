
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","۶�����ϰ�");
  set ("long", @LONG
������۶�������ϰ��������￴ȥ��۶��������һ�澵�����ڵ��ϣ���
Ө��͸����紵�������淺������΢������������̵�Ʈ��һ�㡣
LONG);

  set("exits", ([ 
 "northeast":__DIR__"dongan3",
 "west":__DIR__"nanan2",
        ]));
  set("objects",([
	  __DIR__"npc/shangren":1,
	  ]));

set("outdoors","nanchang");
  
  set("valid_startroom", 1);
  setup();
 
}

