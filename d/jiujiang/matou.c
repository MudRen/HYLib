
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","�Ž���ͷ");
  set ("long", @LONG
�����ǾŽ�����ͷ�����ﴬֻ�ǳ��࣬��Ϊ�������������ˡ��ϱ�
���Ǿ��ǾŽ��ı����ˡ�
LONG);

  set("exits", ([ 

  "south":__DIR__"beimen",
  "north":__DIR__"jiangbei",
         ]));
set("outdoors","jiujiang");
  set("valid_startroom", 1);
  setup();
 
}

