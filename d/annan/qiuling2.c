
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
�����ǰ��ϳ��ϵ�һƬ����أ����������ƽ�����ɫ����ʯ����
��״��ɳʯ·����������û������֮�У���Ϊ�⸽����ǿ�˳�û����
�˼�����������������
LONG);

  set("exits", ([ 

  "southwest":__DIR__"qiuling1",
  "northeast":__DIR__"qiuling3",
  "east":__DIR__"qiuling5",  
       ]));
    set("objects", ([
"quest/skills2/wakuang/kuang/kuangmai" : 2,
       
        ]));
set("outdoors","annan");
  
  set("valid_startroom", 1);
  setup();
 
}

