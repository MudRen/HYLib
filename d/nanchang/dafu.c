
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�ӻ�¥");
  set ("long", @LONG
�ݴ�����������䣬��Ϊ������巺�֮��¦������ױ̨������
���һ��Ϊ�����λ�ı�������Ϊ�ӻ�¥���������ƹݡ���������
��һ����֮�ҡ���˵��ҵ�������������ϲ����׸�������Ů��
����Ҫ���б������ף������˲���������ʿ��
LONG);

  set("exits", ([ 

  "east":__DIR__"nandajie1",
  "enter":__DIR__"tingyuan",
      ]));

set("outdoors","nanchang");
  
  set("valid_startroom", 1);
  setup();
 
}

