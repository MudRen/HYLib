// Room: yabi6.c

#include <ansi.h>
#include <room.h>

inherit ROOM;
#include "tiao.c"

void init()
{
        add_action("do_pa", "pa");       
}

void create()
{
	set("short", HIG"�±�"NOR);
	set("long", @LONG
������������������������������ͱ�֮�ϡ���������ȥ��ֻ����������
�Ƶ�һƬ��ã�������й�ɽ�紵������������ɽ�ڹ⻬ƽ����Ҫ��û��֧��
�㣬��������Ҳ�������㡣
LONG);	

        set("outdoors", "�����");
	
	setup();
	
}

int do_pa(string arg)
{
	object me;
	me=this_player();
        if (me->is_busy() || me->is_fighting())
                return notify_fail("����æ���ء�\n");
	if ( !arg || (arg != "down" && arg != "up"))
       		return notify_fail("��Ҫ��������\n");	
	if (arg =="down"){
          if ((int)me->query_temp("tengacc") <= 0)
       	     return notify_fail(HIR"�����Ѿ��ž������޷������������ˣ�\n"NOR);
	  message_vision(HIG"$N���������������ȥ��\n"NOR, me);
	  me->move(__DIR__"yabi7");
	  me->add_temp("tengacc",-1);
          me->start_busy(1);
	  tell_room(environment(me), me->name() + "������������������������\n", ({ me }));
	  }
	if (arg =="up")	{	
          message_vision(YEL"$N���������������ȥ��\n"NOR, me);
	  me->move(__DIR__"yabi5");
	  me->add_temp("tengacc",1);
          me->start_busy(1);
	  tell_room(environment(me), me->name() + "������������������������\n", ({ me }));
	  }
      return 1;
}
