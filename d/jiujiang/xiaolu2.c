
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","С·");
  set ("long", @LONG
�����ǽ��ߵ�С·�������ǰ��յľ����ˡ���������������������
һ��紵������ˮ�ĳ�ʪ��Ϣ�˱Ƕ�������������Լ������������ˮ��
ߺ�ȵ�������
LONG);

  set("exits", ([ 

  "northeast":__DIR__"xiaolu3",
  "southwest":__DIR__"xiaolu1",
  "north":__DIR__"shadi",
  
         ]));

  set("valid_startroom", 1);
  set("outdoors","jiujiang");
  setup();
 
}

