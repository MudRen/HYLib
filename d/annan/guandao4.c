
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��ӵ�");
  set ("long", @LONG
����������·���������ĺ�������ʳ�����ɫ�������ϱ��ǰ��ϵı��š�
���������������������Щ���֡������������кܶ೵��һ������
�ľ���
LONG);

  set("exits", ([ 

  "south":__DIR__"guandao3",
  "north":__DIR__"matou",
       ]));
    set("objects", ([
        "quest/skills2/wunon/dalie/dalie" : 2,
       
        ]));
set("outdoors","annan");
  
  set("valid_startroom", 1);
  setup();
 
}

