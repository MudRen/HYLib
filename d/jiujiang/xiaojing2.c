
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","С��");
  set ("long", @LONG
��������С�����Ա��ǹ���������ǰ���ƺ�����·����������˺�
�ࡣ�������һƬ��������ʱ�д�ӵĹٱ�����������߹����ŵ�·��
�İ��ն���������ȥ��
LONG);

  set("exits", ([ 

  "west":"/d/xiangyang/caodi4",
  "southeast":__DIR__"xiaojing1",
  
         ]));

  set("valid_startroom", 1);
  set("outdoors","jiang");
  setup();
 
}

