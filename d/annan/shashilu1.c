
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɳʯ·");
  set ("long", @LONG
��������ɳʯ·��һ��紵�������������ɳ���������һƬ������
�Ĵ���ȥһƬƽ̹����ʱ����������ͷ�Ϸɹ���
LONG);

  set("exits", ([ 

  "northwest":__DIR__"xiaolu2",
  "southeast":__DIR__"shashilu2",
       ]));
 
set("outdoors","annan");
  
  set("valid_startroom", 1);
  setup();
 
}

