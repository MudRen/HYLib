
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��ϼ��");
  set ("long", @LONG
��ϼ��λ����ض��࣬�����뻪�Ƿ���ԣ������������������ϼ
������ɫɳʯ�ѻ���Զ��֮�������ƣ�����������ϼ���������ԣ�����
��ɫ�����������
LONG);

  set("exits", ([ 
 "northwest":__DIR__"huagai-feng",
 "southwest":__DIR__"tianhuo-feng",
       ]));
  set("objects",([
   __DIR__"npc/youke":2,
  ]));
  
  set("outdoors","cbs");
  
  set("valid_startroom", 1);
  setup();
 
}

