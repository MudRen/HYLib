
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɽ��");
  set ("long", @LONG
�����Ǹ�ɽ�ԡ����Ｘ��û��ʲô�ˡ���˵���ﾭ����ǿ����û��
�㲻���ӿ��˽Ų���
LONG);

  set("exits", ([ 
 "northeast":__DIR__"shangang1",
 "westdown":__DIR__"shanlu1",
       ]));

set("outdoors","nanchang");
  
  set("valid_startroom", 1);
  setup();
 
}

