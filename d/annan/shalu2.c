
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɳʯ·");
  set ("long", @LONG
��������ɳʯ·����������˺��١���˵���ﾭ����ǿ�˳�û����
����С��������
LONG);

  set("exits", ([ 

  "northeast":__DIR__"shalu1",
  //"west":__DIR__"shulin1",
       ]));
    set("objects", ([
"quest/skills2/wunon/non/nontian" : 2,
    
        ]));
set("outdoors","annan");
  
  set("valid_startroom", 1);
  setup();
 
}

