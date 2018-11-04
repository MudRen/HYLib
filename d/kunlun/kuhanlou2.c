// kuhanlou2.c
// Date: cck 6/6/97

#include <ansi.h>
#include <room.h>

inherit ROOM;

void init();
int do_duanmo(string arg);

void create()
{
	set("short", "�ຮ¥����");
	set("long", @LONG
ÿ��¥���϶������˽�ʵ��ľ¥�壬�˽��ε�ǽ�����������ȴ󴰡�
����ǽ�������������������ź͸��ֵĻ��񣬲���ר�ŵ����ּ���������
���¼�������������������ֻ�ܿ���Χ�����ܵ��������ѵ���ɼ�֣�����
ͨ�������̼��ͺ������Ĺ����İ취����ö���ѧ���β����׷��
LONG
	);

	set("exits", ([
		"up" : __DIR__"kuhanlou3",
		"down" : __DIR__"kuhanlou1",
	]));

	setup();
}

void init()
{
		set("times", random(20));
		set("item_count", 2);

		add_action("do_duanmo", "duanmo");
                add_action("do_duanmo", "see");
}

int do_duanmo(string arg)
{
		object ob, me = this_player();

		if ( (int)me->query("kar") < 20 )
		return notify_fail("��Ҫ��ʲô��\n");

               if ( !arg && (arg != "huaxiang") && (arg != "wall") )
		return notify_fail("����Ҫ��Ħʲô������\n");

		if ( query("item_count") < 1 || me->query_temp("count", 1) <= query("times",1) )
		{
			me->add_temp("count", 1);
			me->receive_damage("jing", 10);
			me->receive_damage("qi", 10);
			return notify_fail("����ϸ��Ħ������ǰ�����˵Ļ����������ǵ����ݺὭ����������𣬲��������������п���\n");
		}

		if ( query("item_count") > 0)
		switch( random(2) )
		{
			case 0:
			add("item_count", -1);
			ob = new("/d/kunlun/obj/weiqi.c");
			ob->move(me);
			ob->delete_temp("count");
return notify_fail("����ϸ��Ħ������ǰ�����˵Ļ����ڻ�������ҵ���һ��Χ��\n");
			break;

			case 1:
			add("item_count", -1);
			ob = new("/d/kunlun/obj/guzheng.c");
			ob->move(me);
			ob->delete_temp("count");
return notify_fail("����ϸ��Ħ������ǰ�����˵Ļ����ڻ�������ҵ���һ�Ź���\n");
			break;
		}

		return 1;
}


int valid_leave(object me, string dir)
{

	if (dir == "up" ) me->add_temp("count", 1);
	else 			 me->add_temp("count", -1);

	return ::valid_leave(me, dir);
}



