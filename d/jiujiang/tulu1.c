
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��·");
  set ("long", @LONG
����������·����ʱ�����ֺ�������۹���һ���ɳ��������ס��
����۾���
LONG);

  set("exits", ([ 
 "north":__DIR__"wguanlu2",
 "south":__DIR__"tulu2",
         ]));
  set("outdoors","jiujiang"); 
  set("valid_startroom", 1);
  setup();
 
}

