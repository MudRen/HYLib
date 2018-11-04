// /d/city/npc/dadao.c

inherit NPC;

void create()
{
	set_name("����", ({"ke shang", "ke", "shang"}));
	set("long", "����һ���ںӱ�һ��������Ŀ��̡�\n");

	set("gender", "����");
	set("attitude", "heroism");

	set("age", 40);
	set("shen_type", -1);
	set("str", 28);
	set("int", 23);
	set("con", 23);
	set("dex", 28);
	set("combat_exp", 130000);

	set_skill("force", 130);
	set_skill("dodge", 130);
	set_skill("unarmed", 130);
	set_skill("parry", 130);

	setup();
	add_money("silver", 30);
	carry_object("/clone/misc/cloth")->wear();
}
