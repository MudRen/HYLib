
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","�ݴ�");
  set ("long", @LONG
�����Ǹ��ݴԡ���������ԼԼ�����������ε�������һ��紵����
����һ�ɳ�ʪ��Ϣ��
LONG);

  set("exits", ([ 

  "northwest":__DIR__"caocong2",
  "southeast":__DIR__"jiangbei",
  
         ]));

  set("valid_startroom", 1);
  set("outdoors","jiang");
  setup();
 
}

