
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"����"NOR);
  set ("long", @LONG
�����ǺϷʵ����š���������˲��١������м����ٱ����ڼ����
���İ��ա��Ա߻�վ�ż������٣�ҫ��������վ�������ͣ��ָ�ֻ�
�š�
LONG);

  set("exits", ([ 

  "north":__DIR__"nandajie3",
  "south":__DIR__"xiaojing1",
       ]));
  set("objects",([
	  __DIR__"npc/bing":2,
	  ]));
set("outdoors","hefei");
  
  set("valid_startroom", 1);
  setup();
 
}

