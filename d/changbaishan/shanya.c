
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɽ��");
  set ("long", @LONG
������һ��ɽ�£�������������Ԩ����������ȥ��˫�Ȳ���������
�������˺��٣�ƽʱ���ǲɲε���Ҳ�������
LONG);

  set("exits", ([ 
 "east":__DIR__"shanlu3",
         ]));
  set("outdoors","cbs");
  
  set("valid_startroom", 1);
  setup();
 
}

