
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��·");
  set ("long", @LONG
����������·������û��ʲô���ˣ���ʱ�����������߹��������
���˲��Ǻܶࡣ
LONG);

  set("exits", ([ 
 "northeast":__DIR__"xiaolu3",
 "southwest":__DIR__"tulu2",
        ]));

set("outdoors","nanchang");
  
  set("valid_startroom", 1);
  setup();
 
}

