
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�ϴ��");
  set ("long", @LONG
�������ϲ����ϴ�֡��ϱ����ϲ��������ˡ�������һ��Ǯׯ����
���οʹ���������߹�������̸����۶�����ķ�⡣ֻ��һ����������
������ʻ������������ȥ������ұ�������ȥ�ˡ�
LONG);

  set("exits", ([ 

  "south":__DIR__"nanmen",
  "north":__DIR__"nandajie1",
  "east":__DIR__"qianzhuang",
        ]));
  set("objects",([
	  __DIR__"npc/man":1,
	  ]));

set("outdoors","nanchang");
  
  set("valid_startroom", 1);
  setup();
 
}

