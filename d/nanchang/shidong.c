
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ʯ��");
  set ("long", @LONG
������һ���ڰ�ɽ����Ȼ�γɵ�ʯ������������һ��ʯ����һ��ʯ
����������û�����ӡ�������һЩ�׹ǺͶ����ʬ�壬�������ݵ�����
��������������ˡ�
LONG);

  set("exits", ([ 

  "north":__DIR__"conglin",
    ]));
  set("objects",([
      __DIR__"npc/xiong":1,
      ]));
  set("valid_startroom", 1);
  setup();
 
}

	