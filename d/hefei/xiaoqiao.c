
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","Сʯ��");
  set ("long", @LONG
����һ������С���ϵ�Сʯ�ţ�վ����ͷ̧����ȥ����������������
�ٻ����ޡ�һƬ������Ȼ�ľ���������һ��ר��Ϊ������Ϣ׼������ͤ��
LONG);

  set("exits", ([ 

  "south":__DIR__"liangting",
  "north":__DIR__"tulu1",
       ]));
 
set("outdoors","hefei");
  
  set("valid_startroom", 1);
  setup();
 
}

