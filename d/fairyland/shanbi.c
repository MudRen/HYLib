// Room: /u/qingyun/jyzj/shanbi.c
// Updated by jpei

inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
���͵�ɽ�ڣ�ȫΪ��Ϊ��Ӳ����ʯ��������ţ���΢��С�ľͻỬ������
��������һƬ��ȣ�����������һɽ����
LONG	);
	set("exits", ([
		"westdown" : __DIR__"cuigu",
		"eastdown" : __DIR__"shangou",
	]));
	set("objects",([
		__DIR__"obj/monkey-rock" : 1,
	]));

if ( random(10) > 7 )
{
	set("objects",([
		__DIR__"npc/xiaohou" : 1,
		__DIR__"obj/monkey-rock" : 1,
	]));
}
	set("outdoors", "kunlun");
	set("no_clean_up", 0);

	setup();
}

void init()
{
	add_action("do_bind", ({"bind", "baoza", "xugu", "bandage", "heal", "zhi", "yizhi", "zhiliao"}));
}

int do_bind(string arg)
{
	object monkey, plywood1, plywood2, yaocao, thread;
	object me = this_player();

	if (arg == "xiao hou" || arg == "hou" || arg == "monkey") {
		if (!(monkey = present("xiao hou", this_object())))
			return notify_fail("����ϸ�������û�к��ӣ�\n");
		if (!monkey->query("get_wound"))
			return notify_fail("����û�����ˣ�\n");
		if (!monkey->query("rock_moved"))
			return notify_fail("����ѹ����ʯ�����ģ�\n");
		if (!(plywood1 = present("zhi tiao 1", me)) || !(plywood2 = present("zhi tiao 2", me)))
			return notify_fail("��ϧ����ͷû���㹻�Ĺ̶��ϹǵĹ��ߡ�\n");
		if (!(thread = present("xi si", me)))
			return notify_fail("��ϧ����ͷû�������õ��ߡ�\n");
		if (!(yaocao = present("yao cao", me)))
			return notify_fail("��ϧ����ͷû�в�ҩ��\n");
		destruct(plywood1);
		destruct(plywood2);
		destruct(thread);
		destruct(yaocao);
		monkey->delete("get_wound");
		monkey->delete("rock_moved");
		me->set_temp("help_monkey", 1);
		new(__DIR__"obj/xianguo")->move(me);
		new(__DIR__"obj/xianguo")->move(me);
		write("��������֦����Ϊ�а壬��С�������϶Ϲǣ��Ѳ�ҩ�����˸��������˴���\n");
		write("�Ǻ����ȻҲ֪�ж�ͼ��������ժ��Щ�ʹ�����Ȼ���ȥѰ��ĺ�����ˣȥ�ˡ�\n");
if (!me->query("jiuyangget"))
{
	        if (me->query_temp("help_monkey") && !present("jiuyang zhenjing", me) && !query("get_wound") && !random(3)) {
		tell_object(me, "��ֻ��ȹ���С���Ȼ���˹�����֨֨�������и���ͣ��\n");
		tell_object(me, "˳��������ָ��ȥ��ֻ��һ����ɫ��Գ�����������ʹ�ࡣ\n");
		new("d/fairyland/npc/dabaiyuan")->move(environment(me));
		me->delete_temp("help_monkey");
          	}
}
//                destruct(monkey);
//		monkey->random_move();
                call_out("dis", 1);
	}
	return 0;
}

void dis(object monkey)
{
	monkey = present("xiao hou", this_object());
	destruct(monkey);
}
