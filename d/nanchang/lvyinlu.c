
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����·");
  set ("long", @LONG
������һ�������Ĵ�·�ϣ�·��������������Ĵ�������ľ������
�У�ʮ�ֵ�ïʢ�������������͵Ĳݵأ�һ����ȥ��������ɫ��ʹ����
��������
LONG);

  set("exits", ([ 

  "south":__DIR__"beimen",
  "northwest":__DIR__"liangting1",
        ]));
 
set("outdoors","nanchang");
  
  set("valid_startroom", 1);
  setup();
 
}

