
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�ݵ�");
  set ("long", @LONG
������Ƭ�ݵء�����������ص������Ѿ���Զ�ˡ����߾��Ǻ�����
���յĽ����ˡ�
LONG);

  set("exits", ([ 

  "northeast":__DIR__"tulu2",
  "north":__DIR__"dalu1",
       ]));
 
set("outdoors","hefei");
  
  set("valid_startroom", 1);
  setup();
 
}

