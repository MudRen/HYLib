
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","������");
  set ("long", @LONG
������һƬ�����֡���ľ��ס�˺�Х�ı��磬������΢ů��һЩ��
��˵�������˲ε�ʢ���أ�Ҳ��֪���ǲ�����ġ�
LONG);

  set("exits", ([ 
 "southwest":__DIR__"shulin2",
 "south":__DIR__"shulin4",
         ]));
  set("objects",([
      __DIR__"npc/she":2,
      ]));
  set("outdoors","cbs");
  
  set("valid_startroom", 1);
  setup();
 
}

