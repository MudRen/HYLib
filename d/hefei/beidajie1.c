
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�����");
  set ("long", @LONG
�����ǺϷʵı���֡��ϱ��ǺϷʵ������ˡ������������������
�㳡���ֵ�������ֻ��������ʿ�����˴���������߹�������ʱ��ͷ
����ش����㼸�ۡ���ʱ��С�̷����ų���������Բ�����
LONG);

  set("exits", ([ 
	  "north":__DIR__"beidajie2",
  "south":__DIR__"center",
     ]));
  
  set("objects",([
  	__DIR__"npc/wushi":1,
  ]));

set("outdoors","hefei");
  
  set("valid_startroom", 1);
  setup();
 
}

