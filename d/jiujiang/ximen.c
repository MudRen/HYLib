
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
�����ǾŽ��������ˡ��кܶ����ú�������ʿ�����������м�����
�������������������ˡ��Ա�վ��һ�����٣�����������ʮ�㣬��ͣ
��ָ�ֻ��š�
LONG);

  set("exits", ([ 
 "east":__DIR__"xidajie2",
 "southwest":__DIR__"wguanlu1",
         ]));
  set("objects",([
	  __DIR__"npc/bing":2,
	  ]));
  set("outdoors","jiujiang"); 
  set("valid_startroom", 1);
  setup();
 
}

