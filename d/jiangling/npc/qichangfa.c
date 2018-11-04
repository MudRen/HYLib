//Edited by fandog, 02/13/2000
#include <ansi.h>;
inherit NPC;

void create ()
{
	set_name("戚长发", ({"qi changfa","qi"}));
	set("nickname", HIB"铁锁横江"NOR);
	set("long", "一个老头儿，嘴里咬着一根短短的旱烟管。他满头白发、满脸皱
纹，但眼中神光炯然，凛凛有威。\n");
	set("gender", "男性");
	set("age", 48);
	set("combat_exp", 10000000);
	set("str", 125);
	set("int", 125);
	set("con", 125);
	set("dex", 125);
	set("per", 125);
	set_skill("force", 220);
	set_skill("dodge", 220);
	set_skill("sword", 220);
	set_skill("parry", 220);
	set_skill("feixian-steps", 220);
	set("max_qi",10000);
	set("max_jing",10000);
	set("max_neili",30000);
	set("qi",10000);
	set("jing",10000);
	set("neili",30000);

	set_skill("liancheng-jian", 320);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.ci" :),
                (: perform_action, "sword.erguang" :),
                (: perform_action, "sword.gan" :),
                (: perform_action, "sword.qian" :),
                (: perform_action, "sword.qu" :),
                (: perform_action, "sword.zhai" :),
                (: perform_action, "sword.zhu" :),
        
        }) );

  

	map_skill("dodge", "feixian-steps");
	map_skill("parry", "liancheng-jian");
	map_skill("sword", "liancheng-jian");
	setup();
		carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/cloth/male-cloth")->wear();
}


