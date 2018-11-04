
inherit NPC;

void create()
{
	set_name("ʩ��", ({ "shi lang", "shi" }));
	set("title", "����ˮ���ᶽ");
	set("shen_type", 1);

	set("gender", "����");
	set("age", 30);
	set("long", "���˾��Ǵ���ˮ���ᶽ��һ���佫����������ݡ�\n");

	set_skill("cuff", 220);
	set_skill("dodge", 220);
	set_skill("taizu-quan", 220);
	set_skill("xiaoyaoyou", 220);
	set_skill("force", 220);
	set_skill("huntian-qigong", 220);
	set_skill("parry", 220);
	set_skill("literate", 200);
	
	map_skill("cuff", "taizu-quan");
	map_skill("parry", "taizu-quan");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("force", "huntian-qigong");
	prepare_skill("cuff", "taizu-quan");

	set_skill("unarmed", 260);
	set_skill("force", 260);
	set_skill("sword", 260);
	set_skill("dodge", 260);
	set_skill("parry", 260);
	set_temp("apply/attack", 250);
	set_temp("apply/defense", 250);
	set_temp("apply/armor", 250);
	set_temp("apply/damage", 230);

	set("combat_exp", 3300000);
	set("attitude", "friendly");
		
	setup();
	carry_object("/clone/armor/tiejia")->wear();
}
