
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
������һ��Ƭ�����֣����ܹ������������������ˮ�����㡣ʹ��
���Ծ��������˿�ˮ���Ա߸������������ȥ��ż���м�ֻС�������
�Դ�������������������
LONG);

  set("exits", ([ 

  "west":__DIR__"guolin",
        ]));
  set("objects",([
    __DIR__"npc/guonong":1,
    ]));
set("outdoors","nanchang");
  
  set("valid_startroom", 1);
  setup();
 
}

