
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ƽ��С�Ե�");
  set ("long", @LONG
�����Ǽ�С�Ե꣬�������������ܺã���С��������ȥæ����ͣ��
ֻ���ſڹ���һ����������ÿ�����Ͼ͵������߸߹������ϵ�ƽ����
�ָ��������ֶ��������������
LONG);

  set("exits", ([ 
  "east":__DIR__"beidajie2",
       ]));

  set("objects",([
	  __DIR__"npc/xiaoer":1,
  ]));
  set("valid_startroom", 1);
  setup();
 
}

