
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","������ջ");
  set ("long", @LONG
�����Ǽ�С�͵ꡣ�⼸����ס����˺ܶ࣬��֪����û�пշ��ӡ�
��С��������ǰ������к��ſ��ˡ��͵����ǰ���Ÿ������ӣ�����д
�š�ס���������������ſڹ�������������������д�š�ƽ�������֡�
LONG);

  set("exits", ([ 
  
	  "north":__DIR__"xijie2",
	  "enter":__DIR__"shuifang",
         ]));
  set("objects",([
	  __DIR__"npc/xiaoer2":1,
	  ]));

  
  set("valid_startroom", 1);
  setup();
 
}

int valid_leave(object me,string dir)
{
	if(!me->query_temp("gived_money")&&dir=="enter")
		if(objectp(present("xiao",environment(me))))
			return notify_fail("��С����ס���㣺�͹٣�����û��Ǯ��!\n");
		else return notify_fail("�ƹ�����溰�����͹٣���Ǯ��ס�갡!\n");
		return ::valid_leave(me,dir);
		return 1;
}
