
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","������");
  set ("long", @LONG
������λ��������ϡ���������֥�̡����շ��м䣬�嶥�ϱ�����
һ�壬��ɫ�����ʯװ����ۣ���ǰ����������£������������һ�㣬
�ʶ�������
LONG);

  set("exits", ([ 
 "northdown":__DIR__"tianchi",
 "south":__DIR__"gusun-feng",
 "southeast":__DIR__"guanri-feng",
 "northwest":__DIR__"luming-feng",
         ]));
  set("outdoors","cbs");
  
  set("valid_startroom", 1);
  setup();
 
}

