
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��Ӫ����");
  set ("long", @LONG
�����ǰ��ϵ�פ����Ӫ�����Ｘ��û�����˽��������Ķ��ǹٱ���
��ʱҲ����������������ſ�������ʿ����վ�ڣ�����һ�������
���ý����ġ����Ͼ��л��кܶ����
LONG);

  set("exits", ([ 

  "southeast":__DIR__"guandao3",
  "north":__DIR__"yingdi",
       ]));
set("objects",([
	  __DIR__"npc/bing":5,
	  __DIR__"npc/daxiang":2,	
	  ]));
set("outdoors","annan");
  
  set("valid_startroom", 1);
  setup();
 
}

