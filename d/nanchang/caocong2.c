
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�ݴ�");
  set ("long", @LONG
�����Ǹ��ݴԣ����涼��������·������ûʲô�ˡ����ﾲ���ģ�
��֪����û�е�����
LONG);

  set("exits", ([ 
 "west":__DIR__"caocong1",
 "east":__DIR__"caocong2",
      ]));
set("objects",([
	__DIR__"npc/she":2,
	]));
set("outdoors","nanchang");
  
  set("valid_startroom", 1);
  setup();
 
}

