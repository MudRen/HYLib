
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��Ժ");
  set ("long", @LONG
������������ҵĺ�Ժ���м���Ѿ��������ȥ����������������
Ҫ��ʲô�����ˡ�
LONG);

  set("exits", ([ 

  "east":__DIR__"dating",
// "up":"/d/job/licaizhu/leitai",
    ]));
 
set("outdoors","nanchang");
  
  set("valid_startroom", 1);
  setup();
 
}

