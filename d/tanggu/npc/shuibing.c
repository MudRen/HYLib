
inherit NPC;

void create()
{
	set_name("ˮ��", ({ "shui bing", "shui", "bing" }));
	set("shen_type", 1);

	set("gender", "����");
	set("age", 20);
	set("long", "һ�����̴���ˮ����\n");
	set_skill("cuff", 150);
	set_skill("dodge", 150);
	set_skill("unarmed", 60);
	set_skill("force", 60);
	set_skill("sword", 60);
	set_skill("dodge", 60);
	set_skill("parry", 60);
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/damage", 60);


	set("combat_exp", 36000+random(5000));
	set("attitude", "friendly");

	setup();
	add_money("silver", random(50));
	carry_object("/clone/armor/tiejia")->wear();
}
