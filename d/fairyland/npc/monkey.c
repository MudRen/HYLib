// monkey.c

inherit NPC;

void create()
{
        set_name("����", ({ "monkey", "hou" }) );
        set("race", "Ұ��");
        set("age", 3);
        set("long", "һֻ�������ϱ�����ȥ�ĺ����\n");

        set("limbs", ({ "ͷ��", "����", "ǰצ", "��צ", "β��" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("combat_exp", 100);
    
	set_temp("apply/attack", 30);
        set_temp("apply/defense", 30);
        set_temp("apply/damage", 30);
        set_temp("apply/armor", 10);

        setup();
}
