
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��԰");
  set ("long", @LONG
������һ����԰���������˺ܶ��ʻ����кܶ������������档����
�ʻ����涷�ޣ����࿪�š��Ա߻��м�����ɽ�����Ͷ��أ���ʯ��ᾣ�
��״���졣���м����ο����Ա���ʫ���ԣ����С���Ů��֪�����ޡ���
���ơ�
LONG);

  set("exits", ([ 
	  "west":__DIR__"nandajie1",
  ]));
 set("objects",([
	 //__DIR__"obj/xianrenzhang":2,
	 __DIR__"npc/xiaojie":1,
	 ]));
set("outdoors","hefei");
  
  set("valid_startroom", 1);
  setup();
 
}

