// /d/city/npc/dadao.c

inherit NPC;

void create()
{
	set_name("�������", ({"jiangbei dadao", "jiangbei", "dadao", "dao"}));
	set("long", "����һ�����н����Ĵ����������ҽ��ᡣ\n");

	set("gender", "����");
	set("attitude", "heroism");

	set("age", 50);
	set("shen_type", -1);
	set("shen", -50000);
	set("str", 28);
	set("int", 23);
	set("con", 23);
	set("dex", 28);
	set("max_qi", 1500);
	set("max_jing", 1000);
	set("neili", 1600);
	set("max_neili", 1600);
	set("jiaji", 60);
	set("combat_exp", 200000);

	set_skill("force", 90);
	set_skill("dodge", 80);
	set_skill("unarmed", 90);
	set_skill("parry", 80);

	setup();
      add_money("gold", 1);
	carry_object("/clone/misc/cloth")->wear();
}
