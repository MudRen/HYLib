//Edited by fandog, 02/15/2000

inherit NPC;

void create ()
{
	set_name("��̹", ({"feng tan","feng"}));
	set("title","�����ߵ���");
	set("long", "\n");
	set("gender", "����");
	set("age", 25);
	set("combat_exp", 100000);
	set("str", 20);
	set("int", 25);
	set("con", 20);
	set("dex", 21);
	set("per", 20);
	set("kar", 20);
	
	set_skill("force", 70);
	set_skill("dodge", 70);
	set_skill("sword", 70);
	set_skill("parry", 70);
	set_skill("feixian-steps", 70);
	set_skill("liancheng-jian", 70);
	map_skill("dodge", "feixian-steps");
	map_skill("parry", "liancheng-jian");
	map_skill("sword", "liancheng-jian");
	set_skill("force", 80);
	set_skill("liancheng-jian", 80);
	set_skill("sword", 80);
	map_skill("sword", "liancheng-jian");
	setup();

	carry_object("/clone/cloth/male-cloth")->wear();
	carry_object("/d/city/obj/changjian")->wield();
}

