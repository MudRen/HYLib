// Room: /u/qingyun/jyzj/shandong.c
// Written by qingyun
// Updated by jpei

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
����һ��Խ��Խխ��ɽ�������ڽ�����Ϊ��Ӳ����ʯ���������ܿ�������
�պ��ܽ�һ�ˣ������С��ͷ�����ײ��ɽʯ������ʮ���ɺ󣬸�����խ����
���Ѳ��������ת���ˣ���������Դ���������ڡ��ٽ����ɺ󣬺���ǰ��
͸�����⣬�ƺ�����һ����ء� 
LONG	);
	set("exits", ([
		"out" : __DIR__"dapingtai",
	]));
	set("no_clean_up", 0);

	setup();
}

void init()
{
  add_action("do_climb", ({"climb", "pa", "zuan"}));
}

int do_climb(string arg)
{
	object me = this_player();

	if (me->query("str") >= 25 && me->query_skill("force",1) < 80) {
		write(HIY"\n���˾�˫�磬�ֽż��ã���ǰ��ȥ�����׵�ȷʵ̫С�����ܽ�ȥ��\n\n"NOR);
		write(HIR"\n��ֻ�����������屻Ƕ�ڿ��У������ƶ��ˡ�\n"NOR);
		me->start_busy(10);
		return 1;
	}
	if (me->query("str") < 25) {
		message("vision", me->name() + "������ǰ��ȥ��\n", environment(me), ({me}));
		write("��������ã�Ѹ�����й���֮����ȥ��\n");
	}
	else {
		message_vision("$N�����ڹ���Ӳ��������ǰ��ȥ��\n", me);
	}
	write("��ǰ��Ȼһ������Ȼ��һ������ɽ�ȣ�\n");
	me->move(__DIR__"cuigu");
	message("vision", me->name() + "�Ӷ������˳�����\n", environment(me), ({me}));
	return 1;
}
