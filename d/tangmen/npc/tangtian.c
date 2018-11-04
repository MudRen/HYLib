// tangtian.c ����


inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("����", ({ "tang tian", "tang" }));
	set("title", "����С����");
	set("shen_type", 1);

	set("str", 30);
	set("gender", "Ů��");
	set("age", 16);
	set("long",
		"�ɰ���С�������Ц����ô�𣬵������������\n"
		"��������һ��а����\n");
	set("combat_exp", 10000);
	set("attitude", "friendly");
	set("inquiry", ([
		"��������" : "������������е�����Ӵ��\n",
		"���Ტ����" : "���ô������\n",
	]));
	
	set("vendor_goods", ({
		"/d/tangmen/obj/zhusun",
		"/d/tangmen/obj/tea",
                "/d/tangmen/obj/jitui",
                "/d/tangmen/obj/jiudai",
	}));

	setup();
	carry_object("/d/tangmen/obj/cloth")->wear();
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
		say("��������۰��Ц��˵������λ" + RANK_D->query_respect(ob) +
			"�����ȱ����������ɡ�\n");
		break;
	case 1 :
		say("����Ц����˵������λ" + RANK_D->query_respect(ob) + 
			"�����˰���������������ز������ݥ��\n");
		break;
	}
}
