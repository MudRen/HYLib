// song.c ��Զ��

inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
	set_name("��Զ��", ({ "song yuanqiao", "song" }));
	set("nickname", "�䵱����");
	set("long", 
		"������������Ĵ���ӡ��䵱����֮�׵���Զ�š�\n"
		"��һ���ɸɾ����Ļ�ɫ���ۡ�\n"
		"���������ʮ������ݳ���������⡣�񵭳�ͣ���Ĭ���ԡ�\n");
	set("gender", "����");
	set("age", 61);
	set("attitude", "peaceful");
	set("class", "taoist");
	set("shen_type", 1);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);
	
	set("max_qi", 7000);
	set("max_jing", 7000);
	set("neili", 9000);
	set("max_neili", 9000);
	set("jiali", 50);
	set("combat_exp", 650000);
	set("score", 60000);
        set_skill("taoism", 180);
	set_skill("force", 100);
	set_skill("taiji-shengong", 180);
	set_skill("dodge", 100);
	set_skill("tiyunzong", 180);
	set_skill("unarmed", 100);
	set_skill("taiji-quan", 180);
	set_skill("parry", 100);
	set_skill("sword", 100);
	set_skill("taiji-jian", 180);
	set_skill("wudang-jian", 180);
	set_skill("literate", 50);
	set_skill("raozhi-roujian", 180);
	set_skill("wudang-mianzhang", 280);
set_skill("claw", 150);
set_skill("strike", 150);
	set_skill("hand", 180);
	set_skill("paiyun-shou", 250);
	set_skill("shenmen-jian", 250);
	set_skill("yitian-zhang", 250);
	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "paiyun-shou");
	map_skill("sword", "taiji-jian");
		map_skill("hand", "paiyun-shou");
			map_skill("strike", "yitian-zhang");
prepare_skill("hand", "paiyun-shou");
prepare_skill("strike", "yitian-zhang");
	create_family("�䵱��", 2, "����");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.zong" :),
                (: perform_action, "unarmed.zhenup" :),
                (: perform_action, "unarmed.tu" :),
                (: perform_action, "unarmed.zhan" :),
                (: perform_action, "unarmed.ji" :),
                (: perform_action, "unarmed.jielidali" :),
                (: perform_action, "hand.leiting" :),
                (: perform_action, "hand.mian" :),
                (: perform_action, "strike.zheng" :),	
                (: perform_action, "sword.lian" :),
                (: perform_action, "sword.chan" :),
                (: perform_action, "sword.chanup" :),
                (: perform_action, "sword.sui" :),
                (: perform_action, "sword.lian" :),
                (: perform_action, "sword.zhenwu" :),
                (: perform_action, "sword.lian" :),                
        }) );
	set("inquiry", ([
		"�ؼ�" : (: ask_me :),
	]));

	set("book_count", 1);

	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/wudang/obj/greyrobe")->wear();
}

void attempt_apprentice(object ob)
{
        if ((int)ob->query("shen") < 100){
		command("say ���䵱���������������ɣ��Ե���Ҫ���ϡ�");
		command("say �ڵ��з��棬" + RANK_D->query_respect(ob) +
			"�Ƿ����ò�����");
		return;
	}
	command("say �ðɣ�ƶ�����������ˡ�");
	command("recruit " + ob->query("id"));
}

string ask_me()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "�䵱��")
		return RANK_D->query_respect(this_player()) + 
		"�뱾��������������֪�˻��Ӻ�̸��";
	if (query("book_count") < 1)
		return "�������ˣ����ɵ��ڹ��ķ����ڴ˴���";
	add("book_count", -1);
	ob = new("/clone/book/force_book");
	ob->move(this_player());
	command("rumor "+this_player()->query("name")+"�õ�̫��ʮ��ʽ����\n");
	return "�ðɣ��Ȿ��̫��ʮ��ʽ�����û�ȥ�ú����С�";
}
