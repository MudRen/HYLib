
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�ϴ��");
  set ("long", @LONG
�����ǺϷʵ��ϴ�֡������ǺϷʵ����Ĺ㳡�ˡ��������˺ܶࡣ
��������ȥ��������һ����԰���кܶ����˶���������ȥ���Ǳ�Ҳ����
��Ц��������
LONG);

  set("exits", ([ 
	  "northwest":__DIR__"center",
  "east":__DIR__"huayuan",
  "south":__DIR__"nandajie2",
   ]));

set("outdoors","hefei");
  
  set("valid_startroom", 1);
  setup();
 
}

