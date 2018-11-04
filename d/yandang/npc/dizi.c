inherit NPC;

void create()
{
	set_name("É½×¯µÜ×Ó", ({ "dizi"}));
	set("gender", "ÄĞĞÔ");
	set("age", 23);

	set("combat_exp", 5000);
	set("shen_type", 1);
       set_skill("unarmed", 30);
	set_skill("sword", 30);
	set_skill("parry", 30);
	set_skill("dodge", 30);
       set_skill("force", 30);



	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/misc/cloth")->wear();
}
	
