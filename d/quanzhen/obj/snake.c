//Cracked by Roath
// animal: snake.c
// Jay 3/18/96

inherit NPC;

void create()
{
        set_name("����", ({ "snake", "she" }) );
	set("race", "Ұ��");
	set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
	set("verbs", ({ "bite", "claw" }) );
        set("age", 4);
        set("long", "һֻ�����������Դ����ߣ�β��ɳɳ���졣\n");
        set("attitude", "peaceful");

        set("msg_fail", "$n��$N˻��һ����ͷ");
        set("msg_succ", "$n˻˻���죬��ͷ����$N���ֶ�������");
        set("msg_trained","$n������Ϣ���ε�$N�Ľ��²�����");
        set("auto_follow",0);
        set("wildness", 9);

        set("str", 26);
        set("cor", 30);

        set("combat_exp", 1000);

        set_temp("apply/attack", 15);
        set_temp("apply/damage", 6);
        set_temp("apply/armor", 2);

        setup();
}
void unconcious()
{
    die();
}
