
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��·");
  set ("long", @LONG
����������·������ĵ�·�ǳ��������ܾ�ɫ��������ʱ�д��
�Ĺٱ�����������߹�����ͷ�Ľ��첻ʱ��ͷ�������㡣�����ǾŽ���
�����ˡ������кܶ�����ˡ�
LONG);

  set("exits", ([ 
 "northeast":__DIR__"ximen",
 "southwest":__DIR__"wguanlu2",
         ]));
  set("outdoors","jiujiang"); 
  set("valid_startroom", 1);
  setup();
 
}

