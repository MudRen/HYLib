
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��ӵ�");
  set ("long", @LONG
����������·���������ĺ�������ʳ�����ɫ�������������������
��������Щ���֡������������кܶ೵��һ�����ֵľ��󡣲�ʱ��
�ɳۿ����������ܹ����ŵ�·�ϵİ��ն���������ȥ��
LONG);

  set("exits", ([ 

  "south":__DIR__"guandao2",
  "north":__DIR__"guandao4",
  "northwest":__DIR__"yingmen",
       ]));

set("outdoors","annan");
  
  set("valid_startroom", 1);
  setup();
 
}

