
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�Ի���");
  set ("long", @LONG
������ǳ���ʮ�����е��Ի��壬��Զ��������ɽ����һֻ���ŵ�
�ͻ����������Ի��塱�����������Ʒ壬���ǹ���塣  
LONG);

  set("exits", ([ 
 "north":__DIR__"guanri-feng",
 "south":__DIR__"guanmian-feng",
         ]));
  set("outdoors","cbs");
  
  set("valid_startroom", 1);
  setup();
 
}

