
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"��������"NOR);
  set ("long", @LONG
�����ǰ��ϵ����š���������˲��١������м����ٱ����ڼ����
���İ��ա��Ա��и��ٱ�ҫ��������վ�������ͣ��������ָ�ֻ��š�
LONG);

  set("exits", ([ 

  "east":__DIR__"xijie2",
  "west":__DIR__"wguanlu1",
       ]));
  set("objects",([
	  __DIR__"npc/bing":2,
	  ]));
set("outdoors","annan");
  
  set("valid_startroom", 1);
  setup();
 
}

