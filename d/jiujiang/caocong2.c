
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","�ݴ�");
  set ("long", @LONG
�����Ǹ��ݴԡ����ܵĲݳ��ü��ߣ���ס��������ߡ�ֻ��������
���ݶ���������
LONG);

  set("exits", ([ 
"north":__DIR__"caocong",
  "northwest":__DIR__"xiaojing1",
  "southeast":__DIR__"caocong1",
  
         ]));

  set("valid_startroom", 1);
  set("outdoors","jiang");
  setup();
 
}

