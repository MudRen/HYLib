
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�����");
  set ("long", @LONG
�����ǺϷʵ�����֡����߾��ǺϷʵ������ˡ���������˽϶ࡣ
�����ǺϷʵ���վ�����������ǹٱ���Ϣ�ĵط���ֻ������վ�ڵĹٱ�
����������
LONG);

  set("exits", ([ 
  "east":__DIR__"xidajie2",
  "west":__DIR__"ximen",
  "north":__DIR__"yizhan",
 "south":__DIR__"yanju",
     ]));
        set("objects", ([
              "/clone/misc/dache" : 1,
        ]) );
set("outdoors","hefei");
  
  set("valid_startroom", 1);
  setup();
 
}

