// Room: /u/jpei/thd/bagua0.c

inherit ROOM;

void create()
{
	set("short", "�����һ���");
	set("long", @LONG
����һƬï�ܵ��һ��ԣ���һ�߽�������ʧ�˷�����ǰ��һ���һ�����
�м�¶��һ��С����
LONG
	);
	set("outdoors","taohua");

	set("exits", ([
		"east" : __DIR__"bagua1",
		"west" : __DIR__"bagua1",
		"south" : __FILE__,
		"north" : __FILE__,
	]));
	setup();
}

void init()
{
	object ob = this_player();
	int step, temp, count;

/*	if (!ob->query_temp("bagua_1")) {
		write("��о�����һ����а��ذ��ԣ����������������������˻�����\n");
		ob->move(__DIR__"xiaoyuan", 1);
		return;
	}*/
	if (ob->query_skill("qimen-wuxing", 1) > 249) {
		write("�������Ѿ������˾Ź����Եı仯����������˼�����߳�����\n");
		ob->move(__DIR__"dongkou", 1);
		tell_room(environment(ob), "ȴ����Ӱ��˸�����Ժ�Ȼ�ֳ�һ��ȱ�ڣ�" + ob->name() + "���������\n", ({ob}));
		return;
	}
	if (!ob->query_temp("bagua_start")) {
		ob->set_temp("bagua_start", 1);
		ob->set_temp("bagua_step", 1);
		ob->set_temp("bagua_temp", 0);
		ob->set_temp("bagua_count", 1);
	}
	temp = ob->query_temp("bagua_temp");
	count = ob->query_temp("bagua_count");
	temp = temp * 2;
	if (count < 3) {
		count++;
	}
	else
	{
		count = 1;
		step = ob->query_temp("bagua_step");
		if (temp == ob->query_temp("bagua_" + step)) {
			if (step == 8) {
				ob->delete_temp("bagua_start");
				ob->delete_temp("bagua_step");
				ob->delete_temp("bagua_temp");
				ob->delete_temp("bagua_count");
				write("�㵹�Ȱ��ԣ�ֱ�����ţ���ǰ�ֳ�һ���Ż������æ̤�˹�ȥ��\n");
				ob->move(__DIR__"dongkou", 1);
				tell_room(environment(ob), "ȴ����Ӱ��˸�����Ժ�Ȼ�ֳ�һ��ȱ�ڣ�" + ob->name() + "���������\n", ({ob}));
				return;
			}
			write("�㷢�ָղ��߹���·�����ϰ��ԣ�������������\n");
			ob->add_temp("bagua_step", 1);
		}
		else {
			ob->delete_temp("bagua_start");
			ob->delete_temp("bagua_step");
			ob->delete_temp("bagua_temp");
			ob->delete_temp("bagua_count");
			write("�㷢���Լ��ȴ��˷�λ�����ܰ����ܲ���ֻ�øϿ�������ʼ�㣡\n");
            ob->move(__DIR__"road5", 1);
			tell_room(environment(ob), "ȴ����Ӱ��˸�����Ժ�Ȼ�ֳ�һ��ȱ�ڣ�" + ob->name() + "���������˳�����\n", ({ob}));
			return;
		}
		temp = 0;
	}
	ob->set_temp("bagua_temp", temp);
	ob->set_temp("bagua_count", count);
}
