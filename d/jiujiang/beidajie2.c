
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�����");
  set ("long", @LONG
�����ǾŽ��ı���֡��ϱ߾��ǾŽ�����ĵط��ˡ�������һ��
��Ժ�����ǾŽ���[����¥]���ſ������Ư���Ĺ������к���·�ϵ���
�ˡ�Ҳ�м�������ç���ȵ���ѬѬ�ش�����ҡ�����߳���
LONG);

  set("exits", ([ 

  "south":__DIR__"center",
  "north":__DIR__"beidajie1",
  "east":__DIR__"chunyuan",
         ]));
  set("objects",([
      __DIR__"npc/susu":1,
      ]));
  set("outdoors","jiujiang"); 
  set("valid_startroom", 1);
  setup();
 
}

