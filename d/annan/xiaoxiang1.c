
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short","С��");
  set ("long", @LONG
��������С�ƽʱ�кܶ��Ʀ��å�ۼ������ֻ������������
�ӣ��Ĳ���������������ڶ���
LONG);

  set("exits", ([ 

  "north":__DIR__"dongjie1",
     ]));
 set("objects",([
	 __DIR__"npc/liumang":1,
	__DIR__"npc/liumang2":1,
	 ]));
set("outdoors","annan");
  set("valid_startroom", 1);
  setup();
 
}

