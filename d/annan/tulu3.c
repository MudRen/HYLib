
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɳʯ·");
  set ("long", @LONG
�����ǰ��ϳ��ϵ�һ��С·����Ϊ������Ҫ���������·��״����
�����ã�ֻ����ɳʯ�̳ɣ�·�������ƽ��һ��紵�������������ɳ
����
LONG);

  set("exits", ([ 

  "northwest":__DIR__"tulu2",
  "northeast":__DIR__"qiuling1",  
       ]));

set("outdoors","annan");
  
  set("valid_startroom", 1);
  setup();
 
}

