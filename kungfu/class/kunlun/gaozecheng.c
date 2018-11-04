// gaozecheng.c (kunlun)

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("�����", ({ "gao zecheng", "gao" }));
	set("long",
		"������ɫ���ۣ�����б�峤������ʮ�˾�����͡�\n"
		"���ֺ�˪��һ��Ҫ�������ǵ�ģ����\n");
	set("gender", "����");
	set("age", 20);
	set("attitude", "heroism");
	set("shen_type", 1);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);

	set("max_qi", 600);
	set("max_jing", 500);
	set("neili", 500);
	set("max_neili", 500);
	set("jiali", 30);
	set("combat_exp", 150000);
	set("score", 10000);

	set_skill("force", 80);
	set_skill("xuantian-wuji", 85);
	set_skill("dodge", 80);
	set_skill("taxue-wuhen", 90);
	set_skill("parry", 80);
	set_skill("sword", 85);
	set_skill("xunlei-jian", 95);
	set_skill("cuff", 80);
	set_skill("zhentian-quan", 90);

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
				"ʦ����׼����Ů���ӣ���ȥ����ʦ械ɡ�");
	 return;
	 }


//	 if(ob->query("appren_hezudao", 1) == 1) {
//	 command("say ǰ�����ҿ������Ц��������ɱ�������ˡ�");
//	 return;
//	 }

	 command("say ��Ȼ"+RANK_D->query_respect(ob)+
				"Ľ������֮����ǧ����������������Ե���������Ӣ��,�Ҿ�������ɡ�");
	 command("recruit " + ob->query("id"));
}
