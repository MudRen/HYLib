// laofu.c ����
// Date: Sep.22 1997

inherit NPC;

void create()
{
        set_name("����", ({ "daxiang", "xiang","xiang" }) );
        set("race", "Ұ��");
        set("age", 20);
        set("long", @LONG
һֻ������ΰ���ˡ������ز������֮����

LONG);
        set("attitude", "aggressive");
        set("shen_type", -1);

        set("limbs", ({ "��ͷ", "����", "��ǰ��", "����", "���" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("combat_exp", 30000);
        set("neili",15800);
        set("max_qi",15800);
        set("max_jing",15800);
        set("max_neili",15800);
        set("jingli",5000);
        set("max_jingli",5000);

        set_temp("apply/attack", 200);
        set_temp("apply/defense", 300);
        set_temp("apply/armor", 1000);
        set_temp("apply/damage", 1000);

        setup();

}

