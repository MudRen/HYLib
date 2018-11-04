// xiaoer3.c ��С��

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("��С��", ({ "xiao er", "xiao", "waiter" }) );
	set("gender", "����" );
	set("age", 22);
	set("long",
		"��λ��С����Ц�����æ��������ʱ������ڲ����ϵ�Ĩ��������\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("rank_info/respect", "С����");
	set("vendor_goods", ({
		__DIR__"obj/jiudai",
		__DIR__"obj/jiouhulu",
		__DIR__"obj/maoniurou",
		__DIR__"obj/gourou",
	}));

	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	object ob;
	
	::init();
	if (interactive(ob = this_player()) && !is_fighting()) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}

void greeting(object ob)
{
	if (!ob || environment(ob) != environment())
		return;
	switch(random(2)) {
	case 0 :
		say("��С��Ц���е�˵������λ" + RANK_D->query_respect(ob) +
			"����������ȱ�ˮ�ưɡ�\n");
		break;
	case 1 :
		say("��С��˵����Ӵ����λ" + RANK_D->query_respect(ob) + 
			"�����˰��������а������Ů������ۡ�ҪƷ��һ����\n");
		break;
	}
}
