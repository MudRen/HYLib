
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�ϲ��㳡");
  set ("long", @LONG
�ϲ��ǽ���ʡʡ�ᣬҲ���ҹ�����ʷ�Ļ����ǣ��ش�����ƫ����
�ӽ��͸��ӵ����Σ�����۶�����������ݺᣬ���ڸ�ɽ�����롢ƽ
ԭ��䣬���ƶ�䣬��Ȼ��Դ�ḻ���ϲ������ƾõ���ʷ�Ļ�����
������2200��������һֱ���Ǹ����ݡ�ʡ�����������������ͣ�¥
̨���������С��ﻪ�챦���˽ܵ��顱֮������
LONG);

  set("exits", ([ 

  "south":__DIR__"nandajie1",
  "north":__DIR__"beidajie2",
  "west":__DIR__"xidajie1",
  "east":__DIR__"dongdajie1",
         ]));
  set("objects",([
	  __DIR__"npc/youke1":1,
	  __DIR__"npc/guniang":1,
"/clone/misc/dache":1,
	  ]));

set("outdoors","nanchang");
  
  set("valid_startroom", 1);
  setup();
 
}

