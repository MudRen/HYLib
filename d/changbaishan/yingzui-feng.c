
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ӥ���");
  set ("long", @LONG
������������ű�ѩ�У����ˡ��Է�Ͳ�ҩ�˵��㼣���������ӥ
��壬��Ϊ��ɽ������ӥ�죬�ʵ���ӥ��塣
LONG);

  set("exits", ([ 
 "westdown":__DIR__"tianchi",
 "southwest":__DIR__"tiebi-feng",
 "southeast":__DIR__"huagai-feng",
 "westup":__DIR__"luming-feng",
         ]));
  set("objects",([
   __DIR__"npc/qiaofu":1,
  ]));
  
  set("outdoors","cbs");
  
  set("valid_startroom", 1);
  setup();
 
}

