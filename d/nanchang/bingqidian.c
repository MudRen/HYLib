
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","������");
  set ("long", @LONG
�����Ǳ����꣬�������ı��������������۸���ˡ�����������
��ͷ�󺹵ػ�����������ֻ��ƹ�����У���һ������������ˡ�
LONG);

  set("exits", ([ 
 "north":__DIR__"xidajie2",
         ]));

set("objects",([
	__DIR__"npc/tiejiang":1,
//	__DIR__"obj/tiekuai":2,
	]));
  
  set("valid_startroom", 1);
  setup();
 
}

