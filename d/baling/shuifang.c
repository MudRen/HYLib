
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","˯��");
  set ("long", @LONG
�������������ջ�������ˡ���������������е����ˣ�����һ
����Ƿ��
LONG);

  set("exits", ([ 
  
	
	  "down":__DIR__"kedian",
         ]));
  set("sleep_room",1);
  set("valid_startroom", 1);
  setup();
 
}

int valid_leave(object me,string dir)
{
	if(dir=="down")
		me->delete_temp("gived_money");
	return ::valid_leave(me,dir);
}

