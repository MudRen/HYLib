
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","������");
  set ("long", @LONG
������һƬ�����֡���ľ��ס�˺�Х�ı��磬������΢ů��һЩ��
Զ���м����ɲε��ˡ�
LONG);

  set("exits", ([ 
 "west":__DIR__"shanlu3",
 "northeast":__DIR__"shulin3",
         ]));
  set("objects",([
      __DIR__"npc/she":2,
      ]));
  set("outdoors","cbs");
  
  set("valid_startroom", 1);
  setup();
 
}

