//Edited by fandog, 02/13/2000

inherit NPC;

void create ()
{
	set_name("���", ({"wan gui","wan"}));
	set("long", "��������ɽ�Ķ��ӣ�����������������΢�����������������������Ǹ����ҹ��ӡ�\n");
	set("title","����������");
	set("gender", "����");
	set("age", 25);
	set("combat_exp", 1000000);
	set("str", 20);
	set("int", 25);
	set("con", 20);
	set("dex", 28);
	set("per", 30);
	set("kar", 20);
	set_skill("force", 80);
	set_skill("dodge", 80);
	set_skill("sword", 80);
	set_skill("parry", 80);
	set_skill("feixian-steps", 80);
	set_skill("liancheng-jian", 280);
	map_skill("dodge", "feixian-steps");
	map_skill("parry", "liancheng-jian");
	map_skill("sword", "liancheng-jian");
	setup();

	carry_object("/clone/cloth/male-cloth")->wear();
	carry_object("/d/city/obj/changjian")->wield();
}  


