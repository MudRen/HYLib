
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɽ·");
  set ("long", @LONG
������һ����ɽ��·��������ǳ���ʮ�����е����壬һ·��ͨ
�������ʯ���շ�ʯ�����ܳ��죬����ʯ��ţ�ɶɣ���ʯ�ѣ����ɵ���
�嶥��
LONG);

  set("exits", ([ 
 "westdown":__DIR__"pubu",
 "eastup":__DIR__"tianhuo-feng",
 "southup":__DIR__"heifengkou",
         ]));
  set("objects",([
   __DIR__"npc/lieren":1,
  ]));
  
  set("outdoors","cbs");
  
  set("valid_startroom", 1);
  setup();
 
}

