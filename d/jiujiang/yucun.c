
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","���");
  set ("long", @LONG
�����Ǹ���壬���������ս�ң������Ѿ�û����ס�ˣ�һƬ������
����ɢ�ҵط���һЩ����������辵ȶ�����������é��ԶԶ���������
LONG);

  set("exits", ([ 

  "south":__DIR__"caodi1",
        ]));

  set("valid_startroom", 1);
  set("outdoors","jiujiang");
  setup();
 
}

