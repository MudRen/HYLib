// Room: /u/jpei/thd/yang.c

#include <localtime.h>

inherit ROOM;

int do_quit();
int do_save();

void create()
{
	set("short", "��");
	set("long", @LONG
���������ǲ����������̫����һ�ˣ������Թ���Ϊ����������Ϊ������
�Ե������Ϊ�Ϸ�������ɽ֮��ˮ֮��Ϊ����
LONG
	);
	set("exits", ([ 
		"northeast" : __DIR__"liangyi",
	]) );

	set("no_clean_up", 0);
	setup();
}

void init()
{
	mixed *local;
	object me = this_player();

	add_action("do_save", "save");
	add_action("do_quit", "quit");
	if (!me->query_temp("liangyi")) {
		local = localtime(time() * 60);
		if (local[LT_MDAY] > 15)
			me->set_temp("liangyi", 1);
		else
			me->set_temp("liangyi", -1);
	}
}

int do_save()
{
	write("���ﲻ׼���̣�\n");
	return 1;
}

int do_quit()
{
	write("���ﲻ׼�˳���\n");
	return 1;
}

