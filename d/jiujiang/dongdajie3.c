
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�����");
  set ("long", @LONG
�����ǾŽ��Ķ���֡�������һ�ұ����꣬�����������������ƹ
�ҵĴ�������ԶԶ��ȥ�����Կ�����������ǰ����һЩ�����ȱ�������
���������⡣�����ǾŽ��Ķ����ˣ��м����ٱ�������������������
���ա�
LONG);

  set("exits", ([ 

 "east":__DIR__"dongmen",
  "west":__DIR__"dongdajie2",
  "north":__DIR__"bingqidian",
  "south":__DIR__"ygrestroom1",
        ]));
     
  set("outdoors","jiujiang"); 
  set("valid_startroom", 1);
  setup();
 
}

