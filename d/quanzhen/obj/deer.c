//Cracked by Roath

inherit NPC;

void create()
{
	set_name("÷��¹", ({ "deer" }) );
	set("race", "Ұ��");
	set("age", 5);
	set("long", "һֻƯ����÷��¹��\n");
	set("attitude", "peaceful");
	
	set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
	set("verbs", ({ "bite", "claw" }) );

	set("combat_exp", 800);

	set("chat_chance", 6);
	set("chat_msg_combat", ({
                "\n÷��¹һת������¹�ǳ��㶥������\n",
        }) );
	
	set_temp("apply/attack", 20);
	set_temp("apply/defense", 50);
	set_temp("apply/damage", 10);
	set_temp("apply/armor", 10);

	setup();
}

	
void unconcious()
{
    die();
}
