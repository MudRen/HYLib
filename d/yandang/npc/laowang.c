inherit NPC;
void create()
{
	set_name("����ͷ", ({ "lao wang", "laowangtou" }));
	set("gender", "����");
	set("age", 67);
       set("title","�ŷ�");
	set("combat_exp", 5000);
	set("shen_type", 1);

	set_skill("unarmed", 30);
	set_skill("sword", 40);
	set_skill("parry", 30);
	set_skill("dodge", 30);
	
	set_temp("apply/attack", 15);
	set_temp("apply/defense", 15);
	set_temp("apply/damage", 20);

	setup();
	carry_object("/clone/misc/cloth")->wear();
}
	
