
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","С·");
  set ("long", @LONG
������һ��С·�������Ӻ��������ߡ������������һ�����ӡ�����
����û��ʲô�ˣ�һƬ������ɪ�����ա������Ӳݴ�����ֻ�м�ֻҰ��
��ʱ����Ľ�ǰ�ܹ���
LONG);

  set("exits",([
	  //"northeast":"/d/yuyang/yincheng",
	  "southwest":__DIR__"cunxi",
	  "south":__DIR__"dadao1",
	  ]));
  set("outdoors","xucheng");
  set("valid_startroom", 1);
  setup();
 
}

