
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"��������"NOR);
  set ("long", @LONG
�����ǰ��ϵ����š���������˲��١������м����ٱ����ڼ����
���İ��ա��Ա���һ������ҫ��������վ�������ͣ��ָ�ֻ��š�
LONG);

  set("exits", ([ 

  "north":__DIR__"suishilu2",
  "south":__DIR__"tulu1",
       ]));
  set("objects",([
	  __DIR__"npc/bing":2,
	  ]));
set("outdoors","annan");
  
  set("valid_startroom", 1);
  setup();
 
}

