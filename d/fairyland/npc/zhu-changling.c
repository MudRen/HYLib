// zhu-changling.c 

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("Öì³¤Áä", ({"zhu changling", "zhu"}));
	set("title", HIR"ºìÃ·É½×¯×¯Ö÷"NOR);
	set("gender", "ÄÐÐÔ");
	set("age", 45);

	set_skill("unarmed", 80);
	set_skill("force", 80);
	set_skill("dodge", 85);
	set_skill("parry", 85);
	set_temp("apply/attack", 40);
	set_temp("apply/defense", 40);
	set_temp("apply/damage", 80);

	set("combat_exp", 170000);
	set("shen_type", -1);
	setup();
	carry_object(__DIR__"obj/pao2")->wear();
	add_money("silver", 50);
}

