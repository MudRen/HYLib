
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"����"NOR);
  set ("long", @LONG
�����ǺϷʵ����š���������˲��١������м����ٱ����ڼ����
���İ��ա����������ң��кܶ�ٱ�Ҳ��������թ�ϰ��յ�Ǯ�ơ�
LONG);

  set("exits", ([ 

  "east":__DIR__"xidajie3",
  "southwest":__DIR__"wguanlu1",
       ]));
  set("objects",([
	  __DIR__"npc/bing":2,
	  ]));
set("outdoors","hefei");
  
  set("valid_startroom", 1);
  setup();
 
}

