
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��ӵ�");
  set ("long", @LONG
����������·���ϱ��ǰ��ϵı��š����������������������Щ��
�֡������������кܶ೵��һ�����ֵľ��󡣲�ʱ�зɳۿ��������
���ܹ����ŵ�·�ϵİ��ն���������ȥ��
LONG);

  set("exits", ([ 

  "south":__DIR__"guandao1",
  "north":__DIR__"guandao3",
       ]));

set("outdoors","annan");
  
  set("valid_startroom", 1);
  setup();
 
}

