
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�����");
  set ("long", @LONG
�����ǺϷʵĶ���֡����߾��ǺϷʵĶ����ˡ��ϱ���һ�ұ����̣�
ֻ�����洫����ƹ���ô���������м�����ʿ�����˴������߳�����ɫ
����ؿ������еĸֵ���
LONG);

  set("exits", ([ 
	  "west":__DIR__"dongdajie2",
  	  "east":__DIR__"dongmen",
  	  "south":__DIR__"bingqipu",
  ]));
  
  set("objects",([
  	__DIR__"npc/maichanggirl":1,
  ]));

  set("outdoors","hefei");
  
  set("valid_startroom", 1);
  setup();
 
}

