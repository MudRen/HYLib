
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","С��");
  set ("long", @LONG
��������С�����Ա��ǹ�����������������˺ܶࡣ�������һƬ
�������Ĵ���ȥһƬƽ̹�������кܶ�Ư����Ұ�����ѹ�Ӣ��ֲ���
ʱ��Ұ�ô���Ľ���������
LONG);

  set("exits", ([ 

  "northwest":__DIR__"xiaojing2",
  "southeast":__DIR__"caocong2",
  "south":__DIR__"chibi",
         ]));

  set("valid_startroom", 1);
  set("outdoors","jiang");
  setup();
 
}

