
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","۶��������");
  set ("long", @LONG
�ӵ������������������ҳ��ơ���ůʱ�ڣ���˿���࣬��������
�������ޣ�������Ŀ��һ·��ɣ��������Ʈ����������ɽ��ˮ����ɫ
�ɲͣ���������䣬���������������ԡ�
LONG);

  set("exits", ([ 

  "south":__DIR__"xiaolu1",
  "east":__DIR__"hupan",
        ]));
  set("objects",([
        __DIR__"npc/youke4":1,
        ]));
set("outdoors","nanchang");
  
  set("valid_startroom", 1);
  setup();
 
}

