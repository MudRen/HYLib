
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
������������ҵĴ��������й���һ�������д��[�вƽ���]����
�Է��ż������ӡ��м���Ѿ�����������ɨ�š�
LONG);

  set("exits", ([ 

  "east":__DIR__"tingyuan",
  "west":__DIR__"houyuan",
     ]));
 

  set("valid_startroom", 1);
  setup();
 
}

