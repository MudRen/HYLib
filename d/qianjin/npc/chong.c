
inherit NPC;

void create()
{
        set_name("ө���", ({ "cong" }) );
        set("race", "Ұ��");
        set("age", 1);
        set("long", "һֻ��������ө���\n");
        set("max_kee", 1);
        set("limbs", ({ "ͷ��", "����", "β��" }) );
        set("verbs", ({ "bite" }) );

        set_skill("dodge", 200);

        setup();
}

