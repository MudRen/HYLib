
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɽ·");
  set ("long", @LONG
��������ɽ·����˵���ﾭ�������˳�û���㲻��С������������
�羰������ɽˮ�续���������¡���ʱ��Ұ�ô���Ľ���������
LONG);

  set("exits", ([ 

  "north":__DIR__"xiaojing3",
  "southeast":__DIR__"shanlu2",
  "southup":__DIR__"shanbao",
       ]));
  set("objects",([
       __DIR__"npc/tufei":1,
       ]));
set("outdoors","hefei");
  
  set("valid_startroom", 1);
  setup();
 
}

