
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�ȴ�����");
  set ("long", @LONG
������һƬһ�������ֺ���ÿ����ľ����ʮ���ɸߣ���Χ��İ������
��ʮ�ɸߵĴ�������һ�飬��ʵ��֦Ҷ��һ�����ɡ��������գ�����
���ڵ�˿��Ҳ�ޡ������������ƺ���Ϫˮ������������
LONG);

  set("exits", ([ 
  "west":__DIR__"shulin6",
  "east":__DIR__"shulin8",

  "northwest":__DIR__"shulin6",
  "southwest":__DIR__"shulin9",
  "north":__DIR__"shulin8",
    ]));
   set("objects",([
	 __DIR__"npc/dushe":2,	
	 ]));
set("outdoors","annan");
  
  set("valid_startroom", 1);
  setup();
 
}

void init()
{
        add_action("do_go","go");;
}
int do_go()
{
if(random(3)){
this_player()->move(this_object());
return 1;
}
}