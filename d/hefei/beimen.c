
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"����"NOR);
  set ("long", @LONG
�����ǺϷʵı��š���������˲��١������м����ٱ����ڼ����
���İ��ա��Ա߻�վ�ż������٣�ҫ��������վ�������ͣ��ָ�ֻ�
�š�
LONG);

  set("exits", ([ 

  "south":__DIR__"beidajie2",
  "north":"/d/cangzhou/nroad3",
       ]));
  set("objects",([
	  __DIR__"npc/bing":2,
	  ]));
set("outdoors","hefei");
  
  set("valid_startroom", 1);
  setup();
 
}

