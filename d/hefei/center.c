
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�Ϸʹ㳡");
  set ("long", @LONG
�����ǺϷʵ����Ĺ㳡�ˡ������ǺϷ������ֵĵضΡ����Ĵ�������
ֻ������ơ����յ������Ⱥ��ߺ�Ƚкõ��������ϴ������ұ߻��и���
���Ĺ������ί���������������Ǹ�������̫ƽ�ģ��Ա���������
����һ������һ�߲�ס��ҡͷ̾����
LONG);

  set("exits", ([ 
	  "north":__DIR__"beidajie1",
  "southwest":__DIR__"xidajie1",
  "southeast":__DIR__"nandajie1",
  "east":__DIR__"dongdajie1",
     ]));
set("objects",([
	__DIR__"npc/yiren":1,
	]));
set("outdoors","hefei");
  
  set("valid_startroom", 1);
  setup();
 
}

