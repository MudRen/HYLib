// Npc: /d/nanshaolin/npc/muren-fighter3.c
// Last Modified by winder on May. 29 2001

inherit NPC;

void create()
{
	set_name("木人", ({ "mu ren" }) );
	set("long", "一个木人");
	set("gender", "机械");
	set("age", 20);
	set("attitude", "friendly");

	set("str",30);
	set("int",30);
	set("con",30);
	set("dex",30);
	set("max_qi", 500);
	set("max_jing", 250);
	set("neili", 500);
	set("max_neili", 500);
	set("jiali", 20);
	set("combat_exp", 20000);

	set_skill("force", 50);
	set_skill("yijinjing", 50);
	set_skill("dodge", 50);
	set_skill("shaolin-shenfa", 50);
	set_skill("club", 50);
	set_skill("weituo-chu", 50);
	set_skill("parry", 50);

	map_skill("force", "yijinjing");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("parry", "weituo-chu");
	map_skill("club", "weituo-chu");
	setup();

        carry_object(__DIR__"qimeigun")->wield();
}

void init()
{
	object ob = this_player();

	if (query("destructing")) return;
	prepare_skill("club", "weituo-gun");
	if (userp(ob))
	{
		say("\n一个木人从暗处向你迎头击来一棍！\n");
		COMBAT_D->do_attack(this_object(), ob, this_object()->query_temp("weapon"), 1);
	}
	if (!present(ob,environment()) || ob->query("qi") < 0 ||
		ob->query("jing") < 0 || ob->query("jingli") < 0)
	{
		ob->move("/d/nanshaolin/daxiong", 1);
		ob->delete_temp("murenxiang");
		tell_object(ob,"你被木人击倒了！昏迷中你似乎被人抬回了大雄宝殿。\n");
	}
	set("destructing", 1);
	//set_ghost(1);
	say("\n木人闪身躲回了暗处。\n");
	call_out("destruct_me", 1);
}

void destruct_me()
{
	destruct(this_object());
}
