
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","С·");
  set ("long", @LONG
��������һ����᫲�ƽ��ɽ·�ϣ�ż������һ�����Ұ�޽�����ͷ
����һЩ��֪����С����������ȥ�����ܴ����ܲ����ʻ��̲��������֣�
����ɽ���ﴵ����������磬������������������һЩ�����Ļ��㡣��
���ǰ��ϵĶ��š���������˺ܶࡣ
LONG);

  set("exits", ([ 

  "west":__DIR__"dongmen",
  "east":__DIR__"xiaolu2",
       ]));
 
set("outdoors","annan");
  
  set("valid_startroom", 1);
  setup();
 
}

