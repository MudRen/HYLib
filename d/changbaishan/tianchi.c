
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","���");
  set ("long", @LONG
��������������ĳ���ɽ����ˣ���غ�ˮ�����峺����һ����� 
�ı�����Ƕ��Ⱥɽ����֮�У�ʹ�������ɾ�������������ɽ����˲Ϣ��
�䣬ʹ������������֣��ʻ������ء�ˮ�������緽�ã�ɽɫ������
���桱�ľ���� 
LONG);

  set("exits", ([ 
 "westup":__DIR__"baiyun-feng",
 "up":__DIR__"tiebi-feng",
 "southup":__DIR__"pingjin-feng",
 "eastup":__DIR__"yingzui-feng",
 "northup":__DIR__"luming-feng",
         ]));
  set("outdoors","cbs");
  
  set("valid_startroom", 1);
  setup();
 
}

