
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
�����ǰ�������֡�������һ�Ҿƹݣ����洫��������ľ��㡣��
���߾Ϳ��Ե����ϵ������ˡ�ֻ����������ĺ������Ӿƹ��г�����ҡ
ҡ�λεس�������ȥ�ˡ�
LONG);

  set("exits", ([ 

  "northeast":__DIR__"center",
  "west":__DIR__"xijie2",
  "northwest":__DIR__"jiuguan",
  "south":__DIR__"suishilu1",
       ]));
 set("objects",([
	 __DIR__"npc/xiaojie":1,
	 ]));
set("outdoors","annan");
  
  set("valid_startroom", 1);
  setup();
 
}

