
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","���Ƿ�");
  set ("long", @LONG
���Ƿ�嶥�ɻ�ɫ��ʯ��ɣ�״���������֮���Ƕ���������ƻ�
�ҷ塣������ϼ�壬�����������ӥ��塣
LONG);

  set("exits", ([ 
 "northwest":__DIR__"yingzui-feng",
 "southeast":__DIR__"zixia-feng",
         ]));
  set("outdoors","cbs");
  
  set("valid_startroom", 1);
  setup();
 
}

