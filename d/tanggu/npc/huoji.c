
inherit NPC;

void create()
{
	set_name("���", ({ "huo ji", "huoji" }));
	set("shen_type", 1);

	set("gender", "����");
	set("age", 20);
	set("long",
		"һ��С��ƣ�������С��\n");
	set_skill("cuff", 20);
	set_skill("dodge", 20);
	set_temp("apply/damage", 15);

	set("combat_exp", 2000);
	set("attitude", "friendly");
		
	setup();
	carry_object("/clone/misc/cloth")->wear();
}
