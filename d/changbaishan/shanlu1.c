
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɽ·");
  set ("long", @LONG
������һ����ɽ��·����·��᫣��ǳ����ߡ��ղŻ��Ǳ̲����࣬
������Ϳ��Կ�����ѩ�ˡ�
LONG);

  set("exits", ([ 
 "eastup":__DIR__"shanlu2",
 "south":"/d/guanwai/milin1",
        ]));
  set("outdoors","cbs");
  
  set("valid_startroom", 1);
  setup();
 
}

