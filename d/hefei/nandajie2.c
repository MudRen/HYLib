
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�ϴ��");
  set ("long", @LONG
�����ǺϷʵ��ϴ�֡���������˲��Ǻܶࡣ�ϱ߿��������Ϸʵ�
�����ˡ�ֻ��һ�ɹ���Ⱥ���ϱ�ӿ�����Ϸʵ����Ŀǰ���Ƚ��ȶ�����
�Ժܶ��˶��������������ˡ�
LONG);

  set("exits", ([ 
	  "north":__DIR__"nandajie1",
  "south":__DIR__"nandajie3",
   ]));
  
  set("objects",([
     __DIR__"npc/daoke":1,
   ]));
set("outdoors","hefei");
  
  set("valid_startroom", 1);
  setup();
 
}

