// sister.c 
// LOTS 1998/10/29

inherit NPC;
//inherit F_SKILL;

void create()
{
	set_name("������", ({ "bao xinyue", "bao", "xinyue" }));
	set("long", 
		"�����ǰ����˵Ĵ�С��,��˵�������Ϸ�.\n"
		"��˵���������䵱����ѧ��������\n");
		
	set("title", "���ǵ�һ��");
	set("nickname", "������");
	set("gender", "Ů��");
	set("age", 18);
	set("shen_type", 1);

	set("neili", 13000);
	set("max_neili", 13000);
	set("max_qi", 12000);
	set("max_jing", 1200);
	set("jiali", 10);
	set("per", 28);

	set_skill("force", 50);
	set_skill("unarmed", 100);
	set_skill("dodge", 100);
	set_skill("parry", 60);
	set_skill("sword", 100);
	set_skill("taiji-jian", 300);
	map_skill("sword", "taiji-jian");
	map_skill("parry", "taiji-jian");

	set_temp("apply/attack", 20);
	set_temp("apply/defense", 20);
	set_temp("apply/damage", 15);

	set("combat_exp", 100000);

	setup();
		carry_object(__DIR__"obj/cloth")->wear();
		carry_object("/clone/weapon/changjian")->wield();
}
