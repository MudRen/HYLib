
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�ݵ�");
  set ("long", @LONG
������һƬ�ݵأ�ƽʱ��С�㾭�������������Ա߻���ʯͷ������
�ӡ����ӣ����滹���˺ܶ��顣
LONG);

  set("exits", ([ 

  "east":__DIR__"huayuan",

     ]));
 
set("outdoors","nanchang");
  
  set("valid_startroom", 1);
  setup();
 
}

