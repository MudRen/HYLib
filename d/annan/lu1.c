
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","С·");
  set ("long", @LONG
��������һ����᫲�ƽ��ɽ·�ϣ�ż������һ�����Ұ�޽�����ͷ
����һЩ��֪����С����������ȥ�����ܴ����ܲ����ʻ��̲��������֣�
����ɽ���ﴵ����������磬������������������һЩ�����Ļ��㡣
LONG);

  set("exits", ([ 

  "east":__DIR__"shulin2",
//  "southwest":"/d/xiangyang/shalu3",
    ]));
  
set("outdoors","annan");
  
  set("valid_startroom", 1);
  setup();
 
}

