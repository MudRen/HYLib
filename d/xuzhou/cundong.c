
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","���");
  set ("long", @LONG
������һ��СС���ӣ�������Ϊ���̵�ԭ�������Ѿ�û����ס�ˡ�
�������������ģ���������ȥ���  
LONG);

  set("exits",([
	  "north":__DIR__"xiaolu1",
	  "east":__DIR__"cunzhong",
	  ]));
  set("outdoors","xucheng");
  set("valid_startroom", 1);
  setup();
 
}

