// suxingh.c
// shilling 97.2

inherit NPC;
inherit F_MASTER;

string ask_me();
string ask_book();

void create()
{
	set_name("���Ǻ�",({"su xinghe","su"}));
	set("gender", "����" );
	set("nickname", "�ϱ�����");
	set("shen_type", 0);
	set("class", "scholar");
	set("age",60);
	set("str", 35);
	set("con", 30);
	set("int", 45);
	set("dex", 35);
	set("per", 30);

	set("no_clean_up",1);

	set("long",
"���˾��Ǻųƴϱ����˵����Ǻӣ���˵�������Ʊ磬 \n"
"��һ�������е����ߣ��������书Ҳ��������֪��\n");

	set("combat_exp", 1500000);
	set("attitude", "peaceful");
	set("book_count", 1);
	set("chat_chance", 1);

	set("inquiry", ([
		"���ܵص�" :(:ask_me:),
		"�ؼ�"     :(:ask_book:),
	]) );

	set("max_qi", 15400);
	set("max_jing", 11400);
	set("neili", 19500);
	set("max_neili",19500);
	set("jiali", 60);
	set("env/wimpy", 60);

	set_skill("force", 150);
	set_skill("dodge", 150);
	set_skill("unarmed", 150);
	set_skill("parry", 150);
	set_skill("blade", 200);
	set_skill("lingboweibu", 380);
	set_skill("beiming-shengong", 380);
	set_skill("ruyi-dao", 380);
	set_skill("liuyang-zhang", 380);
	set_skill("zhemei-shou", 380);
	set_skill("literate", 100);

	map_skill("unarmed", "liuyang-zhang");
	map_skill("parry", "ruyi-dao");
	map_skill("blade", "ruyi-dao");
	map_skill("dodge", "lingboweibu");
	map_skill("force", "beiming-shengong");
	prepare_skill("hand","zhemei-shou");
	prepare_skill("strike","liuyang-zhang");	
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 250);
	set("chat_chance_combat", 90);  
	set("chat_msg_combat", ({
                (: perform_action, "blade.shishiruyi" :),
                (: perform_action, "blade.shishiruyi" :),
                (: perform_action, "blade.ruyi" :),
                (: perform_action, "blade.ruyi" :),
                (: perform_action, "dodge.lingbo" :),
                (: perform_action, "dodge.lingbo" :),
                (: exert_function, "strike.zhong" :),                
                (: exert_function, "strike.zhong" :),                
	}) );

	create_family("��ң��", 2, "����");
	set("title","��ң�ɵڶ��������");
	setup();
	carry_object("clone/cloth/cloth")->wear();
	carry_object("clone/weapon/gangdao")->wield();
}


void attempt_apprentice(object ob)
{

	if (ob->query_int() < 30) {
		command("shake"+ ob->query("id")); 
		command("say " + RANK_D->query_respect(ob) + 
			"�Ƿ�Ӧ����ѧ���϶��µ㹦��");
 return;
	}

	command("say �ðɣ��Ҿ��������ˣ����Ҫ���Ŭ������");
	command("recruit " + ob->query("id"));
 }

string ask_book()
{
	object me,ob;
	mapping fam; 
	ob=this_player();
	if (!(fam = ob->query("family")) 
		|| fam["family_name"] != "��ң��")
	{
		return"��Ҫ�ؼ��͵ü�����ң�ɡ�";
	}
	command("sigh");
	return"���ɵ��书�ؼ�����һ�������ܵĵط�����Ҳûȥ����";
}
string ask_me()
{
	object me,ob;
	mapping fam; 
	ob=this_player();
	if (!(fam = ob->query("family")) 
		|| fam["family_name"] != "��ң��")
	{
		return"��Ҫ֪���ܵ��͵ü�����ң�ɡ�";
	}
	command("sigh");
	return"���ɵ��ܵ��ڻ�ɽ֮�ϣ����Ǽ��ա�������Ȥ����ȥ������";
}

void recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		ob->set("class", "scholar");
}
