// /beijing/npc/shiwei2.c
// Last modified by winder 2003.10.10

inherit NPC;

void create()
{
	set_name("骁骑营侍卫", ({ "shi wei", "shi", "wei" }));
	set("age", 32);
	set("gender", "男性");
	set("long", "骁骑营侍卫个个都是是紫禁城中的好手，千万别去招惹。\n");
	set("attitude", "peaceful");

	set("str", 30);
	set("dex", 30);
	set("combat_exp", 100000);
	set("shen_type", 1);

	set_skill("unarmed", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("sword", 100);
	set_skill("force", 100);
	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/damage", 60);
	set_temp("apply/armor", 60);

	set("chat_chance_combat", 10);
	set("chat_msg_combat", ({
		"骁骑营侍卫喝道：亡命狂徒，京城之中，岂得由你猖狂？\n",
	}));
   set("max_neili",8500);
    set("neili",8500);
    set("qi",8500);
    set("eff_qi",8500);
    set("max_qi",8500);

    set("jing",8500);
    set("eff_jing",8500);
    set("max_jing",8500);
        set_skill("force", 180+random(180));

        set_skill("unarmed", 180+random(180));
        set_skill("blade", 180+random(180));
        set_skill("parry", 180+random(180));
        set_skill("dodge", 180+random(180));
        set_skill("kuang-blade", 180+random(180));
        map_skill("blade", "kuang-blade");
        map_skill("parry", "kuang-blade");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "blade.leitingpili" :),
                (: perform_action, "blade.kuang" :),
                (: random_move :),
        }) );	
	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/armor/tiejia")->wear();
}

void init()
{
	object ob;
	::init();
	if (interactive(ob = this_player()) && 
		(int)ob->query_condition("killer")) {
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob);
	}
}

int accept_fight(object me)
{
	command("say 这可是你活腻了自找的，休得怪我无情。\n");
	me->apply_condition("killer", 500);
	kill_ob(me);
	return 1;
}
