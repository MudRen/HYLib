// wushi.c

inherit NPC;
// inherit F_SKILL;

void create()
{
	set_name("��ʿ", ({ "wu shi", "shi" }));
	set("gender", "����");
	set("age", random(10) + 20);
	set("str", 25);
	set("dex", 16);
	set("long", "һ�������˰�������ʿ��\n");
	set("combat_exp", 50000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set_skill("unarmed", 80);
	set_skill("force", 80);
	set_skill("blade", 80);
	set_skill("dodge", 80);
	set_skill("parry", 80);
	set("neili", 1000); 
	set("max_neili", 1000);
	set("jiali", 10);

	setup();
//	carry_object("/d/city/npc/obj/tiejia")->wear();
//	carry_object("/d/feitian/obj/wushidao")->wield();
}

