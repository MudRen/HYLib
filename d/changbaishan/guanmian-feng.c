
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�����");
  set ("long", @LONG
�����������ѩ�壬λ��������������塢����ٲ�����������
����ҪΪ��ɫ�ĸ�ʯ�����겻���Ļ�ѩ��Զ��֮�ļ��԰ף�ѩʯ�ѱ磬
����֮�£�ѩ�Ⱘ��������ε��ɫ����س��У���߷�Ȥ��
LONG);

  set("exits", ([ 
 "northwest":__DIR__"longmen-feng",
"northeast":__DIR__"tianhuo-feng",
"north":__DIR__"wohu-feng", 
         ]));
  set("outdoors","cbs");
  	set("objects", ([
"quest/skills2/wakuang/kuang/kuangmai" : 2,

	]));
  set("valid_startroom", 1);
  setup();
 
}

