//Cracked by Roath
// monkey.c 

inherit NPC;

void create()
{
	set_name("����", ({ "monkey" }) );
	set("race", "Ұ��");
	set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
	set("verbs", ({ "bite", "claw" }) );
	set("age", 25);
	set("long",
		"��ֻ���������������������£�����ʱ�����ζ�ؿм��������ҡ�\n");
	set("combat_exp", 5000);
        set("shen_type", -1);
	set("attitude", "peaceful");
	
	set("water", 200);
	set("food", 200);

	set("apply/attack", 10);
	set("apply/defense", 10);


	set_skill("unarmed", 25);
	set_skill("parry", 20);
	set_skill("dodge", 20);

	setup();
}
void unconcious()
{
    die();
}
