
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","ɳ·");
  set ("long", @LONG
������Ƭɳ·�������볤�������Ǻ�Զ�������Ź�����ȥ�ĳ�����
�����ӿ����н��ĽŲ���
LONG);

  set("exits", ([ 

  "northeast":__DIR__"shalu2",
  "southwest":__DIR__"caodi2",
  
         ]));

  set("valid_startroom", 1);
  set("outdoors","jiujiang");
  setup();
 
}

