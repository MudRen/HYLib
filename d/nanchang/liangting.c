
inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short","����ͤ");
  set ("long", @LONG
����������ͤ�����ο���Ϣ֮�á�������������ӭ���������
������һ����������ȥ��۶���������ķ�⾡���۵ף�ֻ������ɻ���
Ҷ��΢����΢΢�ζ�����ʱ��С�۴��д������Ϸ�Ů���ö��ĸ�������
�������������ַ��ơ���εΪһ�����С��������������ơ�֮�䡣
LONG);

  set("exits", ([ 
"south":__DIR__"xidajie2",
         ]));

set("outdoors","nanchang");
  
  set("valid_startroom", 1);
  setup();
 
}

