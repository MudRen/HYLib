
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","ɳ·");
  set ("long", @LONG
������Ƭɳ·�������볤�����Ǻ�Զ�������߾����㽭�Ͱ��յĽ�
���ˡ�
LONG);

  set("exits", ([ 
  "northeast":"/d/wuyi/path15",
  "west":__DIR__"shalu2",
  
         ]));

  set("valid_startroom", 1);
  set("outdoors","jiujiang");
  setup();
 
}

