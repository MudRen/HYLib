
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","Ǯׯ");
  set ("long", @LONG
������һ��Ǯׯ�����Ǯׯ������������ܺã�����Ǯ���˺ܶࡣ
Ǯׯ�ϰ������������ˣ�����Ļ�������к�����Ǯ�Ŀ��ˡ�
LONG);

  set("exits", ([ 
	  "south":__DIR__"dongdajie2",
   ]));

  set("objects",([
	  __DIR__"npc/chang":1,
    ]));
  set("valid_startroom", 1);
  setup();
 
}

