// Room: /u/qingyun/jyzj/cuigu1.c
// Updated by jpei

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIG"���"NOR);
	set("long", @LONG
����������ܸ�ɽ���ƣ��ƺ�ب��������δ������������ѩ����ƣ��վ�
���ͣ������޷��ʵǶ��룬����һ���߷���סȥ·���޷�����ǰ�У��ݵ�����
�߰�ͷҰɽ���ͷ�Բݣ����˺������ܣ���(tree)��ʮ��ֻ������ң�������
��֮����������ӱ��أ��������շ������
LONG	);
	set("exits", ([
		"south" : __DIR__"cuigu",
	]));
	set("item_desc", ([
		"tree" : "һ�ò���ߵ�������Ƥ(bark)�����ۣ�������������֦��(twig)��\n",
		"twig" : "���С֦������ز��ߵ������ϡ�\n",
		"bark" : "��Ƥ�Ծ��Գ�����ɫ��\n",
	]) );
	set("objects",([
		__DIR__"npc/shanyang" : 2,
		__DIR__"npc/monkey" : 2,
		__DIR__"npc/xiaohou" : 1,
	]));
	set("outdoors", "kunlun");
	set("no_clean_up", 0);
	set("twig_count", 10);
	set("bark_count", 10);

	setup();
}

void init()
{
	add_action("do_break", ({"break", "zhe", "zheduan", "zhai"}));
	add_action("do_tear", ({"tear", "si", "che"}));
}

void reset_twig()
{
	set("twig_count", 10);
	delete("twig_call_out");
}

void reset_bark()
{
	set("bark_count", 10);
	delete("bark_call_out");
}

int do_break(string arg)
{
	object me = this_player();

	if (arg == "twig" || arg == "zhi" || arg == "zhi tiao") {
		if (query("twig_count")) {
			message_vision("$N����ż⣬������ס��һ��С��֦���þ���������������\n", me);
			add("twig_count", -1);
			new(__DIR__"obj/twig")->move(me);
			return 1;
		}
		else {
			if (!query("twig_call_out")) {
				remove_call_out("reset_twig");
				set("twig_call_out", 1);
				call_out("reset_twig", 600);
			}
			return notify_fail("�����Ѿ�û��ʲôС��֦�ɹ������ˡ�\n");
		}
	}
	return 0;
}

int do_tear(string arg)
{
	object me = this_player();

	if (arg == "bark" || arg == "shupi" || arg == "shu pi") {
		if (query("bark_count")) {
			message_vision("$N����˺��һ����Ƥ�������˼��£��������һ��ϸ˿��\n", me);
			add("bark_count", -1);
			new(__DIR__"obj/thread")->move(me);
			return 1;
		}
		else {
			if (!query("bark_call_out")) {
				remove_call_out("reset_bark");
				set("bark_call_out", 1);
				call_out("reset_bark", 600);
			}
			return notify_fail("����㽫��Ƥȫ������ѽ����\n");
		}
	}
	return 0;
}
