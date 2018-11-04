// zhanchun.c (kunlun)

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("ղ��", ({ "zhan chun", "zhan", "chun" }));
	set("long",
		"���Ǻ�̫����ϲ���ĵ��ӣ����õ�Ҳ��Ϊ������\n");
	set("gender", "Ů��");
	set("age", 24);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 25);
	set("int", 24);
	set("con", 28);
	set("dex", 26);
	set("per", 26);

	set("max_qi", 600);
	set("max_jing", 400);
	set("neili", 500);
	set("max_neili", 500);
	set("jiali", 30);
	set("combat_exp", 50000);
	set("score", 5000);

	set_skill("force", 40);
	set_skill("xuantian-wuji", 65);
	set_skill("dodge", 60);
	set_skill("taxue-wuhen", 65);
	set_skill("parry", 55);
	set_skill("sword", 60);
	set_skill("xunlei-jian", 65);
	set_skill("leg", 50);
	set_skill("chuanyun-tui", 60);


	map_skill("force", "xuantian-wuji");
	map_skill("dodge", "taxue-wuhen");
	map_skill("leg", "chuanyun-tui");
       map_skill("sword", "xunlei-jian");

       prepare_skill("leg", "chuanyun-tui");



	create_family("������", 5, "����");
	setup();
	carry_object("/d/kunlun/obj/sword")->wield();
	carry_object("/d/kunlun/obj/pao3")->wear();
}


void attempt_apprentice(object ob)
{
if(ob->query("gender")=="����"){
	 command("fear");
	 command("say "+RANK_D->query_respect(ob)+
				"ʦ����׼�����е��ӣ���ȥ����ʦ��ȥ�ɡ�");
	 return;
	 }

//         if(ob->query("appren_hezudao", 1) == 1) {
//	command("say ʦ�����ҿ������Ц����ȴ�����򲻸ҵģ�");
//	return;
//	}

	command("say �ðɣ��Ҿ������㣬����һЩƤë����");
	command("recruit " + ob->query("id"));
}
