
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�ϴ��");
  set ("long", @LONG
�����ǺϷʵ��ϴ�֡��ϱ߾��ǺϷʵ������ˡ�������һ��ϷԺ��
������������������ֵ�������ϷԺ�����ⲻ�ȴ�ǰ��ֻ��ϷԺ������
�Ѿ������˻ҳ������Ҳ���ſڴ��ź�Ƿ��
LONG);

  set("exits", ([ 
	  "north":__DIR__"nandajie2",
  "south":__DIR__"nanmen",
  "east":__DIR__"xiyuan",
   ]));
   
   set("objects",([
     __DIR__"npc/xiaohunhun":1,
   ]));
   
set("outdoors","hefei");
  
  set("valid_startroom", 1);
  setup();
 
}

