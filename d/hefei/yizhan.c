
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��վ");
  set ("long", @LONG
�����ǺϷʵ���վ���������Ĺٱ���Ϣ֮�á��м���ʿ����������
��Ϣ���Ա߻�ι���ż�ƥ������ȱ�����ϣ��Ѿ��ݹ�����ˡ�
LONG);

  set("exits", ([ 
   "south":__DIR__"xidajie3",
     ]));
  set("objects",([
	  __DIR__"npc/bing2":2,
	  ]));
set("outdoors","hefei");
  
  set("valid_startroom", 1);
  setup();
 
}

