// liumang.c ��å

inherit NPC;

void create()
{
	set_name("��å", ({ "liu mang", "liu" }));
	set("gender", "����");
	set("age", 19);
	set("long", "����һ���������ֺ��е���å�����õ��ǰװ����ֵģ�Ҳ����ǰ�й�Ǯ��\n");
	
	set("combat_exp", 1000);
	set("shen_type", -1);
set("qi",10000000);
set("max_qi",10000000);
set("eff_qi",10000000);
set("max_jing",10000000);
set("eff_jing",10000000);
set("jing",10000000);



	set("attitude", "peaceful");
	
	set_skill("unarmed", 20);
	set_skill("dodge", 20);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);

	setup();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver",2);
}
