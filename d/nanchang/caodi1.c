
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�ݵ�");
  set ("long", @LONG
������һƬ��ݵء����ܾ�ɫ��������ʱ���ο��߹���һ����紵
��������ͷ�����Ѷ��ˡ�
LONG);

  set("exits", ([ 

  "south":__DIR__"xiaojing2",
  "north":__DIR__"caodi2",
  "east":__DIR__"guolin",
        ]));
 
set("outdoors","nanchang");
  
  set("valid_startroom", 1);
  setup();
 
}

