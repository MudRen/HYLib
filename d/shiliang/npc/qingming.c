// shiqing.c

inherit NPC;

void create()
{
	set_name("������ʦ", ({ "shiqing chanshi", "chanshi", "shiqing" }) );
        set("title", "ʮ���·���");
	set("gender", "����");
	set("age", 20);
	set("long",
		"����һ����������ĺ��С�\n");
	set("combat_exp", 1200000);
        set("shen_type", -1);
	set("attitude", "aggressive");

	set_skill("unarmed", 300);
	set_skill("parry", 300);
	set_skill("blade", 300);
	set_skill("dodge", 300);

	setup();
        carry_object("/d/shaolin/obj/dao-cloth")->wear();
        carry_object("/clone/weapon/gangdao")->wield();
	add_money("silver", 10);
}
