
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","ɳ��");
  set ("long", @LONG
������һƬɳ�ء�����û��ʲô�ˡ������Ӳݴ�����ֻ�м�����ʯ
ͷɢ�ҵط��ڵ��ϡ���Զ����ȥ�����Կ��������ƾɵ���塣
LONG);

  set("exits", ([ 

  "south":__DIR__"xiaolu2",
         ]));
  set("objects",([
	  __DIR__"obj/stone":2,
	  ]));

  set("valid_startroom", 1);
  set("outdoors","jiujiang");
  setup();
 
}

