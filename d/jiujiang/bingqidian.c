
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","������");
  set ("long", @LONG
�����Ǹ������ꡣ��������ս���������������������ر�á���
��������æ����ͣ����֪��Ϊ�ĸ������ڴ�����������¿�ȥ��ֻ����
����ѻ��˺ܶ����������ǹ���ȣ�������ʽ��Ӧ�о��С�ֻ��ƹ����
�У���һ������������ˡ�
LONG);

  set("exits", ([ 

  "south":__DIR__"dongdajie3",

         ]));
  set("objects",([
	  __DIR__"npc/tiejiang":1,
	  ]));

  
  set("valid_startroom", 1);
  setup();
 
}

