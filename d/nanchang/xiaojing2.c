
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","С��");
  set ("long", @LONG
������һ��С������ʤ�ż���������������Ȼ���֮�У�
�㲻��Ϊ��Χ������ɫ�������ˡ�������ɽˮ���г��ϲ���
���ųǵĶ��ط�ò��
LONG);

  set("exits", ([ 

  "southwest":__DIR__"xiaojing1",
  "north":__DIR__"caodi1",
        ]));
 
set("outdoors","nanchang");
  
  set("valid_startroom", 1);
  setup();
 
}

