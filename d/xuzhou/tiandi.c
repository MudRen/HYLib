
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","���");
  set ("long", @LONG
������һƬ����ء������Ѿ������ˣ�������Ұ�ݡ�һ��紵����
�㲻�ɵĴ��˸���ս���Ա��м��ô�������֦�Ѿ����㣬������ɢ����
�ż�ֻ��ѻ������������Ƶؽ��š�
LONG);

  set("exits",([
	  "north":__DIR__"cunzhong",
	  "east":__DIR__"dadao3",
	  ]));
  set("outdoors","xucheng");
  set("valid_startroom", 1);
  setup();
 
}

