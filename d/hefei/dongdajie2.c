
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�����");
  set ("long", @LONG
�����ǺϷʵĶ���֡����������������ǳ����֡�������һ��Ǯׯ��
Ǯׯ�Ľ����������������ҫ���������⡣Ǯׯ���ſ�վ�ż������ڣ���
��ش��������������ˡ�
LONG);

  set("exits", ([ 
	  "west":__DIR__"dongdajie1",
      "east":__DIR__"dongdajie3",
      "north":__DIR__"qianzhuang",
  ]));
  
  set("objects",([
  	__DIR__"npc/qigai":1,
  ]));

  set("outdoors","hefei");
  
  set("valid_startroom", 1);
  setup();
 
}

