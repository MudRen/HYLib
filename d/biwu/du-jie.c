// dujie.c

inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
	set_name("渡劫", ({ "du-jie", "jie" }) );
	set("title", "少林长老");
	set("gender", "男性");
	set("age", 90);
	set("long",
		"这是一个面颊深陷，瘦骨零丁的老僧，他脸色惨白，象一张纸一样。\n");

	set("attitude", "peaceful");
	set("class", "bonze");
	set("combat_exp", 2500000);
	set("score", 200000);

	set("str", 30);
	set("int", 30);
	set("cor", 30);
	set("cps", 30);
	set("con", 30);

	set("qi", 14000);
	set("max_qi", 12000);
	set("neili", 14000);
	set("max_neili", 12000);
	set("jiali", 90);

	create_family("少林派", 35, "弟子");
	assign_apprentice("弟子", 0);

	set_skill("force", 150);
	set_skill("whip", 380);
	set_skill("parry", 180);
	set_skill("dodge", 180);

	set_skill("hunyuan-yiqi", 350);
	set_skill("riyue-bian", 380);
	set_skill("shaolin-shenfa", 180);

	map_skill("force", "hunyuan-yiqi");
	map_skill("whip",  "riyue-bian");
	map_skill("parry", "riyue-bian");
	map_skill("dodge", "shaolin-shenfa");
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 250);

	setup();
	carry_object("/d/shaolin/obj/changbian")->wield();
}
