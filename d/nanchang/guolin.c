
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
������һ��Ƭ�����֣����ܹ������������������ˮ�����㡣ʹ��
���Ծ��������˿�ˮ���Ա߸������������ȥ��ż���м�ֻС�������
�Դ�������������������������һ���ũס��é���ݡ�
LONG);

  set("exits", ([ 

  "west":__DIR__"caodi1",
  "east":__DIR__"guolin1",
  "north":__DIR__"guolin2",
  "south":__DIR__"maocaowu",
        ]));
 
set("outdoors","nanchang");
  
  set("valid_startroom", 1);
  setup();
 
}

