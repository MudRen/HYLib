// xihuazi.c (kunlun)

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("������", ({ "xi huazi", "xi" }));
	set("long",
		"���������ɵ�������ӣ�������ף�����ʮ�ֱ��ꡣ\n");
	set("gender", "����");
	set("age", 26);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 30);
	set("int", 23);
	set("con", 25);
	set("dex", 28);

	set("max_qi", 800);
	set("max_qi", 800);
	set("max_jing", 600);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 30);
	set("combat_exp", 400000);
	set("score", 1000);

	set_skill("force", 95);
	set_skill("xuantian-wuji", 105);
	set_skill("dodge", 80);
	set_skill("taxue-wuhen", 100);
	set_skill("parry", 100);
	set_skill("sword", 101);
	set_skill("xunlei-jian", 105);
	set_skill("cuff", 105);
	set_skill("zhentian-quan", 110);
	set_skill("throwing", 80);
	set_skill("mantian-huayu", 95);


	map_skill("force", "xuantian-wuji");
	map_skill("dodge", "taxue-wuhen");
	map_skill("sword", "xunlei-jian");
	map_skill("cuff", "zhentian-quan");
	prepare_skill("cuff", "zhentian-quan");

	create_family("������", 5, "����");
	setup();
	carry_object("/d/kunlun/obj/sword")->wield();
	carry_object("/d/kunlun/obj/pao3")->wear();
}

void attempt_apprentice(object ob)
{
      if(ob->query("gender")=="Ů��"){
	 command("fear");
	 command("say "+RANK_D->query_respect(ob)+
				"ʦ����׼����Ů���ӣ���ȥ����ʦ�ȥ�ɡ�");
	 return;
	 }
if(ob->query_skill("xuantian-wuji",1)<60){
	 command("hmm");
	 command("say "+RANK_D->query_respect(ob)+
				"��������޼���̫��ҿɲ������㡣");
	 return;
	 }

//	 if(ob->query("appren_hezudao", 1) == 1) {
//	 command("say ǰ�����ҿ������Ц��������ɱ�������ˡ�");
//	 return;
//	 }
	 command("say ��Ȼ"+RANK_D->query_respect(ob)+
				"��ôŬ�����Ҿ�������ɡ�");
	 command("recruit " + ob->query("id"));
}




