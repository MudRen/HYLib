
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�����");
  set ("long", @LONG
�������ϲ��Ķ���֡��������ϲ������ġ��������������������
�����������ϱ���һ��ҩ�꣬�������⻹����һ�󵭵���ҩ�������
��������������˺ܶ࣬���������ߵ�۶������ȥ��
LONG);

  set("exits", ([ 

  "south":__DIR__"yaodian",
   "east":__DIR__"dongdajie2",
   "west":__DIR__"center",
         ]));
  set("objects",([
	  __DIR__"npc/liumang":1,
	  ]));

set("outdoors","nanchang");
  
  set("valid_startroom", 1);
  setup();
 
}

