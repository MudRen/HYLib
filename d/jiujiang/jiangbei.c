
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","��������");
  set ("long", @LONG
�����ǳ����ı��������˳��������ǽ����ľ����ˡ��������˺ܶ࣬
���ǳ˴����ÿͺ������������̷������������������ڶ���Զ�����м���
��ʻ�˹��������˳������Ϳ��Ե��Ž��ˡ�
LONG);

  set("exits", ([ 
  "south":__DIR__"matou",
  "northeast":__DIR__"xiaolu1",
  "northwest":__DIR__"caocong1",
  "north":"/d/hefei/caodi2",
         ]));

  set("valid_startroom", 1);
  set("outdoors","jiang");
  setup();
 
}

