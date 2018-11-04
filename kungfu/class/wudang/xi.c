// xi.c ����Ϫ

inherit NPC;

void create()
{
	set_name("����Ϫ", ({ "zhang songxi", "zhang" }));
	set("nickname", "�䵱����");
	set("long", 
		"��������������ĵ�������Ϫ��\n"
		"��������ʮ�꣬�����ܸɣ������Ƕ�ı���ơ�\n");
	set("gender", "����");
	set("age", 40);
	set("attitude", "peaceful");
	set("class", "swordsman");
	set("shen_type", 1);
	set("str", 26);
	set("int", 30);
	set("con", 26);
	set("dex", 28);
	
	set("max_qi", 11200);
	set("max_jing", 1800);
	set("neili", 11500);
	set("max_neili", 11500);
	set("jiali", 50);
	set("combat_exp", 800000);
	set("score", 50000);

	set_skill("force", 90);
	set_skill("taiji-shengong", 90);
	set_skill("dodge", 90);
	set_skill("tiyunzong", 90);
	set_skill("unarmed", 90);
	set_skill("taiji-quan", 95);
	set_skill("parry", 95);
	set_skill("sword", 90);
	set_skill("taiji-jian", 190);
	set_skill("taoism", 80);
	set_skill("literate", 90);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.zong" :),
                (: perform_action, "unarmed.zhenup" :),
                (: perform_action, "unarmed.zhan" :),
                (: perform_action, "unarmed.ji" :),
                (: perform_action, "unarmed.jielidali" :),
                (: perform_action, "sword.lian" :),
                (: perform_action, "sword.chan" :),
                (: perform_action, "sword.chanup" :),
                (: perform_action, "sword.sui" :),
                (: perform_action, "sword.lian" :),
                (: perform_action, "sword.lian" :),
                (: perform_action, "sword.lian" :),                
        }) );
	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");

	create_family("�䵱��", 2, "����");

	setup();
	carry_object("/clone/weapon/changjian")->wield();
}
