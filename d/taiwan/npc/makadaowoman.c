// makadaowoman.c 马卡道族女子
// Last Modifyed by Ahda on Jan. 4 2002

inherit NPC;

void create()
{
	int age;
	age = 20 + random(40);
	
	set_name("马卡道族女子", ({ "makadao woman", "woman"}));
	set("gender", "女性");
	set("age", age);

	set_skill("unarmed", 20);
	set_skill("dodge", 20);
	set("apply/attack", 15);
	set("apply/defense", 15);
	set("apply/damage", 5);
	set("combat_exp", 150+age*10);
	set("shen_type", 1);
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

