
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","�һ�Դ");
  set ("long", @LONG
�һ�Դ����λ��®ɽ���Ͽ������С���������Ƴ����ȣ���
��®ɽ�⡣ս��ĩ�ڣ���Ԫǰ223�꣩�����ʱ���ؽ����幥��
�����ٴ����������أ�����²�˳������һ��������ۻ����ʱ��
һ������Я�������ӣ�������®ɽ�������������ѣ�������Ϊ
���գ���Ϯ���磬�������Ϊ������������˶��á� 
LONG);

  set("exits", ([ 

//  "northwest":__DIR__"caocong2",
  "south":__DIR__"caocong2",
  
         ]));

  set("valid_startroom", 1);
  set("outdoors","jiang");
  setup();
 
}

