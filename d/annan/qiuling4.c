
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

  "south":__DIR__"qiuling3",
  "northeast":__DIR__"xiaolu2",
       ]));
    set("objects", ([
"quest/skills2/wakuang/kuang/kuangmai" : 1,
       
        ]));
set("outdoors","annan");
  
  set("valid_startroom", 1);
  setup();
 
}

