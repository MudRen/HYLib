// chaxiaoer


inherit NPC;
inherit F_DEALER;


void create()
{
	set_name("��С��", ({ "xiao er", "xiao" }));
	set("shen_type", 1);

	set("str", 30);
	set("gender", "����");
	set("age", 25);
	set("long",
		"�����С����æ�Ÿ������Ͳ裬���̡�");
	set("combat_exp", 500);
	set("attitude", "friendly");
		
	set("vendor_goods", ({
		__DIR__"obj/yan",
		__DIR__"obj/wan",
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
		say("��С�������˵������λ" + RANK_D->query_respect(ob) +
			"�����ϸ����ϲ衣\n");
		break;
	case 1 :
		say("��С��˵������λ" + RANK_D->query_respect(ob) + 
			"Ҫ��Ҫ������ˮ��������\n");
		break;
	}
}
