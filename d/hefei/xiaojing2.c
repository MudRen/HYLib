
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","С��");
  set ("long", @LONG
��������С���������ǰ��յ��ϲ��ˣ���������˺��١��������
һƬ�������Ĵ���ȥһƬƽ̹����ʱ����������ͷ�Ϸɹ���
LONG);

  set("exits", ([ 

  "northeast":__DIR__"xiaojing1",
  "southwest":__DIR__"xiaojing3",
       ]));
  
set("outdoors","hefei");
  
  set("valid_startroom", 1);
  setup();
 
}

