
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","Ǯׯ");
  set ("long", @LONG
�����ǾŽ�������Ǯׯ�����Ǯׯ��ʷ�ƾã��������ߡ��ܶ��˶�
��Ǯ�浽���Ǯׯ�ϰ�������������к��ſ��ˡ�
LONG);

  set("exits", ([ 

  "south":__DIR__"xidajie1",
        ]));
 set("objects",([
	 __DIR__"npc/qian":1,
	 ]));
  set("valid_startroom", 1);
  setup();
 
}

