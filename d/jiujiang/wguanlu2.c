
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��·");
  set ("long", @LONG
����������·���кܶ������������ߵľŽ���ȥ���㲻���ӿ�����
���ĽŲ���
LONG);

  set("exits", ([ 
 "northeast":__DIR__"wguanlu1",
 "south":__DIR__"tulu1",
         ]));
  set("outdoors","jiujiang"); 
  set("valid_startroom", 1);
  setup();
 
}

