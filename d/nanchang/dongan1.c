
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","۶��������");
  set ("long", @LONG
������۶�����Ķ�����۶�������������ǰ����Ҷ����ʻ�ں��ϣ����
�ɻ�׺�ں��С���ʱ�и����Ӻ��еĻ����ϴ������ö��������������
�ͺܶ࣬�㲻��Ϊ����ľ�ɫ������������
LONG);

  set("exits", ([ 
 "north":__DIR__"dongan2",
  "east":__DIR__"xidajie2",
  "southwest":__DIR__"dongan3",
  "southup":__DIR__"qiao",
         ]));
  set("objects",([
	  __DIR__"npc/youke2":1,
	  ]));

set("outdoors","nanchang");
  
  set("valid_startroom", 1);
  setup();
 
}

