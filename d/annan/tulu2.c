
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɳʯ·");
  set ("long", @LONG
�����ǰ��ϳ��ϵ�һ��С·����Ϊ������Ҫ���������·��״����
�����ã�ֻ����ɳʯ�̳ɣ�·�������ƽ��һ��紵�������������ɳ
�������ߵ���������Լ����һ��С·.
LONG);

  set("exits", ([ 

  "north":__DIR__"tulu1",
  "southeast":__DIR__"tulu3",
//  "southwest":__DIR__"shulin3",  
       ]));

set("outdoors","annan");
  
  set("valid_startroom", 1);
  setup();
 
}

