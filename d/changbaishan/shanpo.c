
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɽ��");
  set ("long", @LONG
������һ��ɽ�£����������£�Ҫ��һ��С�Ļ�����ȥ��׼�Ƿ���
��ǡ����ڱ�ѩ�ܶ࣬�㲻��С��������
LONG);

  set("exits", ([ 
 "west":__DIR__"shanlu2",
// "eastup":"/d/clone/room/lingwu/jingzhai/wolong1",
       ]));
  set("outdoors","cbs");
  
  set("valid_startroom", 1);
  setup();
 
}

