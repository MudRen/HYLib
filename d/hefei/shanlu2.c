
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��ɽ");
  set ("long", @LONG
��ɽ�羰���ںϷ�����9���ﴦ������284�ס��������컣��ļ���ɫ
���������®�ݸ�ѧ������ӽ��ɽԻ����ɽ��Ǣ��Ц����ɽ������Σ���ɽ
������ױ����ɽ��壵����ԣ�Ω����Ҳ����ѩ���񿪣�ԾȻ����ɫ�ӡ�
LONG);

  set("exits", ([ 

  "northwest":__DIR__"shanlu1",
  "southwest":__DIR__"shanlu3",
       ]));
  
set("outdoors","hefei");
  
  set("valid_startroom", 1);
  setup();
 
}

