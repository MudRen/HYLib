// /u/dubei/gumu/jqg/npc/puren1
// by dubei
inherit NPC;

void create()
{
	set_name("丫鬟", ({ "ya huan", "ya", "huan" }));
	set("long",
		"一位十七八岁的小丫鬟。\n");
	set("gender", "女性");
	set("age", 18);
	set("attitude", "friendly");
	set("shen", 1);
	set("str", 25);
	set("int", 24);
	set("con", 28);
	set("dex", 26);
	set("per", 26);

	set("max_qi", 300);
	set("max_jing", 800);
	set("neili", 800);
	set("max_neili", 800);
	set("jiali", 10);
	set("combat_exp", 50000);

	set_skill("force", 30);
 
 
	setup();
 
//	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/misc/cloth")->wear();

//	carry_object("/clone/armor/cloth")->wear();
}

 
