inherit NPC;
void create()
{
    set_name("����", ({ "ju mang", "mang" }) );
	set("race", "Ұ��");
	set("age", 70);
    set("long", "һ��������������������\n");
    set("attitude", "aggressive");
	set("limbs", ({ "ͷ��", "����", "β��", "����" }) );
	set("verbs", ({ "bite" }) );
        set("str", 190);
        set("con", 190);
	set("combat_exp", 350000);
	set_temp("apply/attack", 150);
	set_temp("apply/defense", 100);
	set_temp("apply/damage", 200);
	set_temp("apply/armor", 300);
	setup();
}

