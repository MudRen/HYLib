
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɽ·");
  set ("long", @LONG
������һ����ɽ��·����·��᫣��ǳ����ߡ�ǰ����һƬ���֡���
���ѩ�Ѿ��ܶ��ˣ�һ��С�ģ��ͻỬ��,���洫��һ����ˮ������
LONG);

  set("exits", ([ 
 "northup":__DIR__"pubu",
 "up":__DIR__"shulin1",
 "westdown":__DIR__"shanlu1",
        ]));
  set("outdoors","cbs");
  	set("objects", ([
"quest/skills2/wunon/non/nontian" : 2,

	]));
  set("valid_startroom", 1);
  setup();
 
}

