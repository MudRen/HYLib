
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�ȴ�����");
  set ("long", @LONG
������һƬһ�������ֺ���ÿ����ľ����ʮ���ɸߣ���Χ��İ����
��ʮ�ɸߵĴ�������һ�飬��ʵ��֦Ҷ��һ�����ɡ��������գ�����
���ڵ�˿��Ҳ�ޡ������������ƺ���Ϫˮ������������
LONG);

  set("exits", ([ 
  "north":__DIR__"shulin1",
  "south":__DIR__"shulin2",

  "northeast":__DIR__"shulin1",
  "west":__DIR__"lu1",
  "southeast":__DIR__"shulin9",
    ]));

 set("objects",([
	 __DIR__"npc/dushe":2,	
	 ]));  
set("outdoors","annan");
  
  set("valid_startroom", 1);
  setup();
 
}

