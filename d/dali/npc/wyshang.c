//Cracked by Kafei
// wyshang.c �����̷�

inherit NPC;

void create()
{
	set_name("�����̷�", ({ "shang fan", "shang", "fan" }) );
	set("long", "һλ��������̷�������һ��ƤëҰζ�ڷ�����\n");

	set("age", 25);
	set("gender", "����");
	set("dalivictim",1);

	set("str", 20);
	set("cor", 20);

    set("combat_exp", 1000);
	set("max_qi", 200);
	set("qi", 200);
	set_skill("dodge", 10);
	set_skill("parry", 10);
	set_temp("apply/attack", 10);
	set_temp("apply/damage", 5);
	set_temp("apply/armor", 5);
	
	set("attitude", "peaceful");
	set("shen_type", 1);

	setup();
	carry_object("/clone/misc/cloth")->wear();
}
