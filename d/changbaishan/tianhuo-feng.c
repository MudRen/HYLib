
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
�򡰷���˫�⣬�б�һ�ߣ��л�Ȼ���ʣ����˲���˼��֮Ȥ������
�����塣����һ�߷�϶���ഫΪ������ˮ��������ʯ���ɫ����ȥ
������̾ᡣվ�ڷ嶥����ĿԶ����Ⱥ�嵹ӳ���Შ���졣  
LONG);

  set("exits", ([ 
 "westdown":__DIR__"shanlu6",
 "northwest":__DIR__"zhinv-feng",
 "northeast":__DIR__"zixia-feng",
 "southwest":__DIR__"guanmian-feng"
         ]));
  set("outdoors","cbs");
  
  set("valid_startroom", 1);
  setup();
 
}

