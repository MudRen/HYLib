
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","���ڷ�");
  set ("long", @LONG
���ڷ嶫��ӥ�������������֯Ů�����������������ڷ��ʯ
��ᾣ�ʯɫ��ڣ�״�����ڣ������������ڷ�������Ԯ���ϣ��ɸ���
���ʤ����
LONG);

  set("exits", ([ 
 "southwest":__DIR__"zhinv-feng",
 "northeast":__DIR__"yingzui-feng",
"down":__DIR__"tianchi", 
         ]));
  set("outdoors","cbs");
  
  set("valid_startroom", 1);
  setup();
 
}

