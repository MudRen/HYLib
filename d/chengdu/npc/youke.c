// youke.c �ο� 
// Last Modifyed by Winder on Dec. 24 2001
//

inherit NPC;

void create()
{
	set_name("�ο�", ({ "youke" }));
	set("gender", "����");
	set("age", 20 + random(30));

	set_skill("unarmed", 20);
	set_skill("dodge", 20);
	set("apply/attack", 15);
	set("apply/defense", 15);
	set("apply/damage", 5);
	set("combat_exp", 750);
	set("shen_type", 1);

	setup();
	carry_object(__DIR__"obj/cloth/male-cloth")->wear();
	carry_object(__DIR__"obj/cloth/male-shoe")->wear();
	add_money("silver", 5);
}
	
