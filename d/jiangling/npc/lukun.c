//Edited by fandog, 02/15/2000

inherit NPC;

void create ()
{
	set_name("³��", ({"lu kun","lu"}));
	set("title","���Ŵ����");
	set("long", "\n");
	set("gender", "����");
	set("age", 26);
	set("combat_exp", 100000);
	set("str", 20);
	set("int", 25);
	set("con", 20);
	set("dex", 21);
	set("per", 20);
	set("kar", 20);
	set_skill("force", 80);
	set_skill("dodge", 80);
	set_skill("sword", 80);
	set_skill("parry", 80);
	set_skill("feixian-steps", 80);
	set_skill("liancheng-jian", 80);
	map_skill("dodge", "feixian-steps");
	map_skill("parry", "liancheng-jian");
	map_skill("sword", "liancheng-jian");
	setup();

	carry_object("/clone/cloth/male-cloth")->wear();
	carry_object("/d/city/obj/changjian")->wield();
}


