
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��Ȫ");
  set ("long", @LONG
�ںڷ�ڹ�����ʯ�����м�ʮ����Ȫ������Ѥ����ɫ�ʰ���Χ����
ʯ��ɳ��Ⱦ�Ľ�ơ���������졢���̣���˸�����ʮɫ��ɢ��������
��������Χ��һƬ����ѩ�أ�������ȷʵ�������ڣ�����������ʵ����
����һ�����¡�    
LONG);

  set("exits", ([ 
 "southwest":__DIR__"heifengkou",
         ]));
  set("outdoors","cbs");
  
  set("valid_startroom", 1);
  setup();
 
}

