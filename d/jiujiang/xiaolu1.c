
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","С·");
  set ("long", @LONG
�����ǽ��ߵ�С·���Ա߾��ǹ����ĳ���������羰������ɽˮ��
�����������¡�һ��紵������ˮ�ĳ�ʪ��Ϣ�˱Ƕ�����
LONG);

  set("exits", ([ 

  "northeast":__DIR__"xiaolu2",
  "southwest":__DIR__"jiangbei",
  
         ]));

  set("valid_startroom", 1);
  set("outdoors","jiujiang");
  setup();
 
}

