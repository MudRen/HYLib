// Room: /u/jpei/thd/dongkou.c
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���һ������Ȼ��������ôһ���Ҷ����ɼ���������֮�ɡ��Ҷ���Χȫ��
�һ��������￴���ں�����ʲôҲ�����������¾����һ��������µ���
�������������󣬷��ǲ����䷨�����ߴ���޷�������
LONG
	);
	set("exits", ([ 
		"out" : __DIR__"road5",
		"enter" : __DIR__"cave",
		"down" : __DIR__"liangyi",
	]) );
	set("no_clean_up", 0);
	set("outdoors","taohua");

	setup();
}

void init()
{
	object me = this_player(), oyf;
	
	add_action("do_quit", "quit");
	
if (!me->query_temp("jyoyf"))
{
	if (objectp(present("jiuyin zhenjing", me))
	 || objectp(present("jiuyin shangjuan", me))
	 || objectp(present("jiuyin xiajuan", me))) {
	 	me->start_busy(2);
	 	oyf = present("ouyang feng", environment(me));
	 	if (oyf) destruct(oyf);
		oyf = new("/kungfu/class/btshan/ouyangfeng");
		oyf->move(environment(me));
		message_vision(HIR"\n��Ȼһ���Ц��Զ��������ֻת�ۼ䣬һ����Ӱ�ͳ����ڶ��ڡ�\n"NOR, me);
		message_vision(HIR"$N��ϸ��ȥ��ԭ�����Ǵ�������������ŷ���塣\n"NOR, me);
		message_vision(HIR"ֻ��������Ц���������첻�������ˣ�û�뵽���õ������澭�Ļ���������ŷ���壡\n\n"NOR, me);
	 	me->set_temp("jyoyf",1);
		oyf->kill_ob(me);
	}
}
}

int valid_leave(object me, string dir)
{
	if (objectp(present("ouyang feng", environment(me)))
	 && (objectp(present("jiuyin zhenjing", me))
	 || objectp(present("jiuyin shangjuan", me))
	 || objectp(present("jiuyin xiajuan", me))))
		return notify_fail("ŷ������һ�����������ӣ���������һ�Σ����������ǰ��\n");
	return ::valid_leave(me, dir);
}

int do_quit()
{
	write("���ﲻ׼�˳���\n");
	return 1;
}
