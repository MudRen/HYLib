
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
�����ǰ��ϵ����֡����߾��ǰ��ϵ������ˣ��м����ٱ���������
�̲��Ź��������ˡ��ϱ���һ�ҿ�ջ���ſڹ��ŵĴ�����ԶԶ�Ϳ���
�����������С�������ſ�������к��ſ��ˡ�
LONG);

  set("exits", ([ 

  "west":__DIR__"ximen",
  "east":__DIR__"xijie1",
  "south":__DIR__"kezhan",
  "north":__DIR__"yanju",
       ]));
 set("objects",([
 __DIR__"npc/jiyinong":1,
 __DIR__"npc/bing":5, 	
 ]));
set("outdoors","annan");
  
  set("valid_startroom", 1);
  setup();
 
}

