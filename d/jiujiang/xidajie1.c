
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�����");
  set ("long", @LONG
����������֡������ǾŽ������ģ��Ӷ��ߴ������������������
������һ��Ǯׯ��������һ�ҷ�ׯ�����洫������Ĳ��㣬��С������
��ǰ������к��ſ��ˡ�
LONG);

  set("exits", ([ 

  "south":__DIR__"fanzhuang",
  "north":__DIR__"qianzhuang",
  "east":__DIR__"center",
  "west":__DIR__"xidajie2",
         ]));
  set("objects",([
	  __DIR__"npc/shangren":1,
	  ]));
  
  set("outdoors","jiujiang"); 
  set("valid_startroom", 1);
  setup();
 
}

