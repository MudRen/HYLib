
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"����"NOR);
  set ("long", @LONG
�����ǾŽ��ı��š�����ش������ش������߾�����ͷ�ˡ�������
���кܶ����˺����ˣ��������ֵúܡ����С��С�����ų��������߹���
�������Լ�����Ʒ���м����ٱ����������������������ˡ�
LONG);

  set("exits", ([ 

  "south":__DIR__"beidajie1",
  "north":__DIR__"matou",
         ]));
  set("objects",([
	  __DIR__"npc/bing":2,
	  ]));
set("outdoors","jiujiang");
  
  set("valid_startroom", 1);
  setup();
 
}

