// shanyang.c

inherit NPC;

void create()
{
        set_name("ɽ��", ({"shan yang", "yang"}));
        set("race", "Ұ��");
        set("age", 5);
        set("long", "һֻ��˳�ɰ���ɽ��\n");

        set("limbs", ({ "ͷ��", "����", "ǰצ", "��צ", "β��" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("combat_exp", 100);
    
	set_temp("apply/attack", 30);
        set_temp("apply/defense", 30);
        set_temp("apply/damage", 30);
        set_temp("apply/armor", 10);

        setup();
}
