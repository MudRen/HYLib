
inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short","Ԭ���Ŷ�Ĺ");
  set ("long", @LONG
Ԭ���Ŷ�Ĺ���׳ơ�Ԭ�Ϲ¶ѡ�������Ĺ�ᡣ�ڳ�����
С�¶����ƺ���ּ�С����ռ��2756ƽ���ף���7.5��.Ĺ
�����ж���С�ذ���
LONG);

  set("exits", ([ 
 "northdown":__DIR__"shanlu1",
         ]));

set("outdoors","hefei");
  
  set("valid_startroom", 1);
  setup();
 
}
