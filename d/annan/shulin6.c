
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
  "west":__DIR__"shulin4",
  "east":__DIR__"shulin7",

  "northwest":__DIR__"shulin7",
  "southeast":__DIR__"shulin4",
  "south":__DIR__"shulin5",
    ]));
   set("objects",([
	 __DIR__"npc/tiger":1,	

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