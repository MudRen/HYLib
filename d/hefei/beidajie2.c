
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�����");
  set ("long", @LONG
�����ǺϷʵı���֣������ǺϷʵı��š�������һ��С�Ե꣬��
�洫����������㣬ֻ����С�����ſ�������к������������ˡ��м�
��������������С�Ե��ſڳ�����ͷ���������ڣ��Ѿ��Ǳ������ˡ�
LONG);

  set("exits", ([ 
	  "north":__DIR__"beimen",
  "south":__DIR__"beidajie1",
  "west":__DIR__"xiaochidian",
       ]));

set("outdoors","hefei");
  
  set("valid_startroom", 1);
  setup();
 
}

