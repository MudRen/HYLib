
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɽ·");
  set ("long", @LONG
������һ��ɽ·��̧ͷ��ȥ�����Կ�����������һ�����������
��Լ���������о���������
LONG);

  set("exits", ([ 
 "up":__DIR__"shanlu5",
 "westup":__DIR__"zhinv-feng",
         ]));
  set("outdoors","cbs");
  	set("objects", ([

"quest/skills2/wunon/dalie/dalie" : 2,

	]));
  set("valid_startroom", 1);
  setup();
 
}

