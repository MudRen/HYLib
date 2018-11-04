// xiaoyaozi.c ��ң��
// shilling 97.2

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("��ң��", ({ "xiaoyao zi", "xiaoyao","zi" }));
	set("title", "��ң�ɿ�ɽ��ʦ");
	set("long", 
		"��������ң�ɿ�ɽ��ʦ��������Ϊ��ң������һ���ڽ�����\n"
		"�����ܽ��ɣ��������ڽ����в��Ǻܶ���֪��������ʵ����\n"
		"����ȴ�ǡ���������������Ѯ��������⣬��ü�԰ס�\n");
	set("gender", "����");
	set("age", 75);
	set("class", "scholar");
	set("attitude", "friendly");
		set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 60);
	set("int", 60);
	set("con", 60);
	set("dex", 60);
	set("per", 60);
	
	set("max_qi", 15500);
	set("max_jing", 13000);
	set("neili", 33000);
	set("max_neili", 33000);
	set("jingli", 2000);
	set("max_jingli", 2000);
	set("jiali", 100);
	set("combat_exp", 9800000);
	set("score", 200000);

	set_skill("force", 300);
        set_skill("yangyanshu", 380);
	set_skill("bahuang-gong", 380);
	set_skill("beiming-shengong", 380);
	set_skill("dodge", 300);
	set_skill("goplaying", 100);
	set_skill("luteplaying", 100);
	
	set_skill("painting", 100);
	set_skill("medicine", 100);
	set_skill("construction", 100);
	set_skill("horticulture", 100);
	set_skill("dramaturgy", 100);
	
	
	set_skill("lingboweibu", 380);
	set_skill("unarmed", 260);
	set_skill("liuyang-zhang", 380);
	set_skill("parry", 260);
	set_skill("blade", 260);
	set_skill("ruyi-dao", 380);
	set_skill("zhemei-shou", 380);
	set_skill("hand", 300);
	set_skill("literate", 300);
	set_skill("strike", 280);
	set_skill("sword", 380);
	set_skill("hand", 280);
	set_skill("qingyun-shou", 380);
	set_skill("panyang-zhang", 380);
	set_skill("liuyue-jian", 380);
	map_skill("force", "beiming-shengong");
	map_skill("dodge", "lingboweibu");
	map_skill("unarmed", "zhemei-shou");
	map_skill("hand", "zhemei-shou");
	map_skill("strike", "liuyang-zhang");
	
	map_skill("parry", "ruyi-dao");
	map_skill("blade", "ruyi-dao");

	prepare_skill("hand","zhemei-shou");
	prepare_skill("strike","liuyang-zhang");
	set("chat_chance_combat", 90);  
	set("chat_msg_combat", ({
                (: perform_action, "blade.shishiruyi" :),
                (: perform_action, "blade.ruyi" :),
                (: perform_action, "dodge.lingbo" :),
                (: perform_action, "strike.zhong" :),
                (: perform_action, "strike.lianzhong" :),
                (: perform_action, "hand.tanmei" :),
                (: perform_action, "hand.zhemei" :),          
	}) );
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 300);
	create_family("��ң��", 1, "��ɽ��ʦ");
	set("class", "taoist");

	setup();
	carry_object(__DIR__"obj/blade")->wield();
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query_skill("beiming-shengong", 1) < 250) {
		command("say ����ң���ڹ���ԴȪ�����ڱ�ڤ�񹦵��ķ���"); 
		command("say " + RANK_D->query_respect(ob) + 
			"�ı�ڤ���Ƿ�Ӧ��������߰���");
		return;
	}

	if (ob->query_int() < 35) {
		command("say ����ң���书�����ӡ���ң�����֡�");
		command("say ����ν����ң������ֻ�ܿ����Լ�ȥ����");
		command("say ����" + RANK_D->query_respect(ob) + "�������ƺ����д���߰���");
		return;
	}
	command("smile");
	command("say �벻���������Ͼ�Ȼ�����˿��Լ̳��ҵ���ң�ķ���");
	command("recruit " + ob->query("id"));
	ob->set("title","��ң�ɻ���ʹ��");
}
