// Room: /u/jpei/thd/taiyin.c

#include <localtime.h>

inherit ROOM;

int do_quit();
int do_save();

void create()
{
	set("short", "̫��");
	set("long", @LONG
������������̫����̫��������֮����Ҳ��������������Ӧ�������е�
���䣬�ڹ�֮�Σ��кڡ��Է�λ�����У���һ������ֱͨ�·��ı����ɹ�ˮ��
LONG
	);
	set("exits", ([ 
		"south" : __DIR__"sixiang",
		"down" : __DIR__"shui",
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
	if (!me->query_temp("sixiang")) {
		local = localtime(time() * 60);
		if (local[LT_HOUR] >= 23 || local[LT_HOUR] < 5)
			me->set_temp("sixiang", 1);
		else
			me->set_temp("sixiang", -1);
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

