
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�����");
  set ("long", @LONG
�����ǺϷʵĶ���֡������ǺϷʵ������ˡ���������˺ܶࡣ��
����������������ֵ��������м��������������ҡҡ�λε��߹���
���ﲻͣ�����ų�͢�޵������ܵ����˶�ԶԶ�����˿�����
LONG);

  set("exits", ([ 
	  "west":__DIR__"center",
      "east":__DIR__"dongdajie2",
  ]));
  
  set("objects",([
  	__DIR__"npc/dizi":1,
  ]));

  set("outdoors","hefei");
  
  set("valid_startroom", 1);
  setup();
 
}

