
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","���Ʒ�");
  set ("long", @LONG
���Ʒ���ʯ��¶����״���ݡ���˵�˷�ֱͨ�칬������ͥ���˼���
�������ݣ���˽����Ʒ塣ɽͷ�����������ƣ���ʹ������Ҳ�������
����������������������塣
LONG);

  set("exits", ([ 
 "northeast":__DIR__"yuzhu-feng",
 "southwest":__DIR__"longmen-feng",
// "eastdown":"/d/clone/room/lingwu/jingzhai/wolong1",
         ]));
  set("outdoors","cbs");
  	set("objects", ([
"quest/skills2/wakuang/kuang/kuangmai" : 2,

	]));
  set("valid_startroom", 1);
  setup();
 
}

