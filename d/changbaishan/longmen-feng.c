
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","���ŷ�");
  set ("long", @LONG
���ŷ�Ϊ����ʮ����֮һ���ڳ�鶺���������������ԣ�����״
���ţ��������š�������������ˮ����������Ա��������������Ϊ
�񱮡�
LONG);

  set("exits", ([ 
 "eastdown":__DIR__"pubu",
 "southeast":__DIR__"guanmian-feng",
 "northeast":__DIR__"tiyun-feng",
         ]));
  set("objects",([
   __DIR__"npc/qiangdao":1,
  ]));
  	set("objects", ([
"quest/skills2/wunon/non/nontian" : 2,

	]));
  set("outdoors","cbs");
  
  set("valid_startroom", 1);
  setup();
 
}

