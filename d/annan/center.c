
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��������㳡");
  set ("long", @LONG
�������ϣ����Ͻ��������ӳ�������˲������׶��а������Ƶ�
ϰ���������Ǻ��ģ�������Ů������ɫ��Ͳȹ������Щ���Ŵ���
�ĸ�Ů���ǽ�����Ů�����ǳ��űش����ң������������ܵ��ꡣ 
LONG);

  set("exits", ([ 
"west":__DIR__"gj1",
"east":__DIR__"gj2",	
  "southwest":__DIR__"xijie1",
  "southeast":__DIR__"dongjie1",
  "north":__DIR__"qingshilu1",
       ]));
 set("objects",([
	 __DIR__"npc/bing2":1,
	 __DIR__"npc/bldizi":1,
	 ]));
set("outdoors","annan");
  
  set("valid_startroom", 1);
  setup();
 
}

