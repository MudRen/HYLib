
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�ȴ�����");
  set ("long", @LONG
������һƬһ�������ֺ���ÿ����ľ����ʮ���ɸߣ���Χ��İ����
��ʮ�ɸߵĴ�������һ�飬��ʵ��֦Ҷ��һ�����ɡ��������գ�����
���ڵ�˿��Ҳ�ޡ�Զ���ƺ��м���������Ϣ��
LONG);

  set("exits", ([ 
  "north":__DIR__"shulin1",
  "south":__DIR__"shulin9",
  //"east":__DIR__"shalu2",
  "southwest":__DIR__"shulin2",
  "west":__DIR__"xiaoxi",
       ]));
 set("objects",([
	 __DIR__"npc/daxiang":1,
	 __DIR__"npc/tiger":1,	
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
