
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�ϴ��");
  set ("long", @LONG
�������ϴ�֡������ǾŽ������š�������ս��ʱ������Ҳ����
ͬ���裬����û����ȥ����ϱ߾��ǾŽ��������ˣ��м����ٱ�����
���������������ˡ�
LONG);

  set("exits", ([ 

  "south":__DIR__"nanmen",
  "north":__DIR__"nandajie1",
  "east":__DIR__"yamen",
         ]));
  set("objects",([
    __DIR__"npc/dufuwei":1,
    ]));
  set("outdoors","jiujiang"); 
  set("valid_startroom", 1);
  setup();
 
}

