
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","СϪ");
  set ("long", @LONG
��������СϪ��Ϫˮ�峺���ף����м�������������ȥ������羰
������ɽˮ�续���������¡������кܶ�Ư����Ұ�����ѹ�Ӣ��ֲ�
��ʱ��Ұ�ô���Ľ���������
LONG);

  set("exits", ([ 

  "east":__DIR__"shulin1",
    ]));
  set("objects",([
	  __DIR__"npc/she":2,
	  ]));
  set("resource/water",1);
set("outdoors","annan");
  
  set("valid_startroom", 1);
  setup();
 
}

