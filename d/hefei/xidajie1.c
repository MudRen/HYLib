
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�����");
  set ("long", @LONG
�����ǺϷʵ�����֡������ǺϷʵ������ˡ�������һ��ҩ�̣���
�ﴫ���������ҩ�㡣�����˱�������������߹������ﲻ֪�������
��ʲô���ƿ�ҩ�̵�����ȳȳ�չյ����˽�ȥ��
LONG);

  set("exits", ([ 
	  "northwest":__DIR__"yaopu",
  "northeast":__DIR__"center",
  "southwest":__DIR__"xidajie2",
     ]));
     
  set("objects",([
  	__DIR__"npc/shangbing":2,
  ]));

set("outdoors","hefei");
  
  set("valid_startroom", 1);
  setup();
 
}

