
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","���Ͼƹ�");
  set ("long", @LONG
������һ�Ҿƹݣ�����������ǳ��ã���С��������ȥ��æ����ͣ
�������ƿ���������ȾƳ�̸���ſ�Ʈ����һ����죬����д�š�����
�ƹݡ��ĸ����֣�ӭ��Ʈ��ƺ����к������������Ŀ��ˡ�
LONG);

  set("exits", ([ 

  "southeast":__DIR__"xijie1",
      ]));
 
  set("objects",([
	  __DIR__"npc/xiaoer":1,
	  ]));
  set("valid_startroom", 1);
  setup();
 
}

