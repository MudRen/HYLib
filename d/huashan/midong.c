// Room: /d/huashan/midong.c
// Date: Look 99/03/25

#include <room.h>
inherit ROOM;

void create()
{
       set("short","�ض�");
       set("long", @LONG
�������һ�ţ�͸���Ӷ���ԶԶ͸������һ˿�����㷢�����ܵĶ�������
������һЩС�ˣ�����ôҲ���������
LONG
     );

	set("exits", ([
		"northeast" : __FILE__,
		"southeast" : __FILE__,
		"southwest" : __FILE__,
		"northwest" : __FILE__,
		"west" : __FILE__,
		"east" : __FILE__,
		"south" : __FILE__,
		"north" : __FILE__,
	]));
	setup();
}

void init()
{
	object ob;
	int jing, jing_cost;

	ob = this_player();
	jing = ob->query("jing");
	jing_cost = ob->query("kar");

	if(jing < jing_cost)
		ob->unconcious();
	ob->add("jing", -jing_cost);
}

int valid_leave(object me, string dir)
{
	if (random((int)me->query("kar")) > 13)
		me->add_temp("mark/steps",1);
	if (random((int)me->query("kar")) < 10)
		me->add_temp("mark/steps",-1); 
        
	if (me->query_temp("mark/steps") == 10)
	{
		me->move(__DIR__"houshan");
		me->delete_temp("mark/steps");
		return notify_fail("��Ϲ��Ϲײ����Ȼ������ǰһ�����Ѿ��������˼������ĺ�ɽ��\n");
	}  

	if (me->query_temp("mark/steps") == -10)
	{
		me->move(__DIR__"siguoya");
		me->delete_temp("mark/steps");
		return notify_fail("���۵ð���������߳���ɽ����\n");
	}
           
	return ::valid_leave(me, dir);
}
