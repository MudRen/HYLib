
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��Ӫ");
  set ("long", @LONG
�����ǰ��ϵ�פ����Ӫ�����Ｘ�����ǹٱ���һ�ӹٱ����������
����������һ������������������ָ�ֻ��ţ������ǹپ���ͷ�ӡ�
��������ʮ�ֵİ��ۣ���Ҵҵ�����
LONG);

  set("exits", ([ 

  "south":__DIR__"yingmen",
       ]));
set("objects",([
	  __DIR__"npc/bing":5,
	  __DIR__"npc/daxiang":2,
	  ]));
set("outdoors","annan");
  
  set("valid_startroom", 1);
  setup();
 
}

