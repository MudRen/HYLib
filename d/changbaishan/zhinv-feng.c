
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","֯Ů��");
  set ("long", @LONG
������ǳ���ʮ�����еĵġ�֯Ů�塱��ɽ������ï�ܣ�����һ��
С·����������ɽ�£���֪��ͨ�����  
LONG);

  set("exits", ([ 
 "eastdown":__DIR__"shanlu4",
 "northeast":__DIR__"tiebi-feng",
 "southeast":__DIR__"tianhuo-feng",
          ]));
  set("outdoors","cbs");
  
  set("valid_startroom", 1);
  setup();
 
}

